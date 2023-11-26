#include <zhele/clock.h>
#include <zhele/iopins.h>

#include "task.h"
#include "rpc.h"

using Led = Zhele::IO::Pa4;

void ConfigureClock();
void BlinkTaskEntry(void* arg);

using BlinkTask = SimpleTask<BlinkTaskEntry, 256>;
using RpcTask = Rpc;

int main()
{
    ConfigureClock();

    bgrt_init();

    SysTick_Config(Zhele::Clock::SysClock::ClockFreq() / 1000);

    BlinkTask::InitPrivilege();
    RpcTask::InitPrivilege();

    BlinkTask::RunPrivilege();
    RpcTask::RunPrivilege();

    bgrt_start();
}

void ConfigureClock()
{
    using namespace Zhele::Clock;

    PllClock::SelectClockSource(PllClock::External);
    PllClock::SetMultiplier(6);
    Apb1Clock::SetPrescaler(Apb1Clock::Div2);
    SysClock::SelectClockSource(SysClock::Pll);
}

void BlinkTaskEntry(void* arg)
{
    constexpr auto _taskDelayMs = 1000;

    Led::Port::Enable();
    Led::SetConfiguration(Led::Configuration::Out);
    Led::SetDriverType(Led::DriverType::PushPull);

    for (;;)
    {
        Led::Toggle();
        bgrt_wait_time(_taskDelayMs);
    }
}


void kernel_preemt_hook()
{
}