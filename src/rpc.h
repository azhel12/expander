#ifndef RPC_H_
#define RPC_H_

#include "task.h"

#include <ArduinoJson.h>

#include <zhele/pinlist.h>
#include <zhele/timer.h>
#include <zhele/usart.h>

#include <native.h>

#include <string_view>

class Rpc : public TaskBase<Rpc, 512, 1>
{
    static constexpr auto _taskDelayMs = 100;

    using Connection = Zhele::Usart1;
    static constexpr auto _baud = 115200;
    static constexpr auto _rxBufferSize = 256;

    using EndTimer = Zhele::Timers::Timer3;

    static char _uartBuffer[_rxBufferSize];

    static constexpr auto _methodKey = std::string_view("method");
    static constexpr auto _paramsKey = std::string_view("params");
    static constexpr auto _parseErrorResult = std::string_view(R"({"error : "parse_error"})");
    static constexpr auto _unknownMethodErrorResult = std::string_view(R"({"error : "unknown_method"})");

    static constexpr auto _pinSetMethodName = std::string_view("setpin");
    static constexpr auto _pinResetMethodName = std::string_view("resetpin");
    static constexpr auto _portKey = std::string_view("port");
    static constexpr auto _pinKey = std::string_view("pin");

    static constexpr auto _okResult = std::string_view(R"({"result" : "ok"})");
    
public:
    static void Entry(void* arg)
    {
        Init();

        for(;;)
        {
            if (EndTimer::IsInterrupt()) {
                EndTimer::ClearInterruptFlag();
                HandleMessage();
            }

            bgrt_wait_time(_taskDelayMs);
        }
    }

private:
    static void Init()
    {
        // Init connection
        Connection::Init(_baud);
        Connection::SelectTxRxPins<Zhele::IO::Pa9, Zhele::IO::Pa10>();
        StartReceive();

        // Init end-detection timer
        EndTimer::Enable();
        EndTimer::EnableOnePulseMode();
        EndTimer::SetPrescaler(1999);
        EndTimer::SetPeriodAndUpdate(1999);
        EndTimer::ClearInterruptFlag();

        // Init gpio (should be in rpc command)
        using controlPinList = Zhele::IO::PinList<Zhele::IO::Pa1, Zhele::IO::Pa2, Zhele::IO::Pa3>;
        controlPinList::Enable();
        controlPinList::SetConfiguration<controlPinList::Configuration::Out>();
        controlPinList::SetDriverType<controlPinList::DriverType::PushPull>();
        controlPinList::Set(0b111);// Clear all
    }

    static void HandleMessage()
    {
        Connection::DmaRx::Disable();

        auto size = _rxBufferSize - Connection::DmaRx::RemainingTransfers();
        _uartBuffer[size] = '\0';

        StaticJsonDocument<256> doc;
        auto deserializeError = deserializeJson(doc, _uartBuffer);
        if (!deserializeError) {
            //TODO:: Dispatch executors here in future
            auto method = doc[_methodKey].as<std::string_view>();
            if (method == _pinSetMethodName) {
                auto portName = doc[_paramsKey][_portKey].as<std::string_view>();
                auto pinNumber = doc[_paramsKey][_pinKey].as<int>();

                if(portName == "PA") {
                    Porta::Set(1 << pinNumber);
                }

                Connection::WriteAsync(_okResult.data(), _okResult.size());
            } else if (method == _pinResetMethodName) {
                auto portName = doc[_paramsKey][_portKey].as<std::string_view>();
                auto pinNumber = doc[_paramsKey][_pinKey].as<int>();

                if(portName == "PA") {
                    Porta::Clear(1 << pinNumber);
                }

                Connection::WriteAsync(_okResult.data(), _okResult.size());
            } else {
                Connection::WriteAsync(_unknownMethodErrorResult.data(), _unknownMethodErrorResult.size());
            }
        } else {
            Connection::WriteAsync(_parseErrorResult.data(), _parseErrorResult.size());
        }

        // Ready to receive next message
        StartReceive();
    }

    /**
     * @brief Start receive input messages
     * 
     * @par Returns
     *  Nothing
    */
    static void StartReceive()
    {
        Connection::EnableAsyncRead(_uartBuffer, 1, FirstByteReceiveInit);
    }

    /**
     * @brief First message receive callback. Start rx-end detector
     * 
     * @param data Received data (unused)
     * @param data Received data (unused)
     * @param data Received data (unused)
    */
    static void FirstByteReceiveInit(void* data, unsigned size, bool success)
    {
        // Receive another bytes
        // TODO:: Add complete callback for detect too big message
        Connection::EnableAsyncRead(&(_uartBuffer[1]), _rxBufferSize -1);
        EndTimer::Start();
    }
};
inline char Rpc::_uartBuffer[Rpc::_rxBufferSize];

#endif //! RPC_H_