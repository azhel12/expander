# Expander
Simple RPC-controlled port expander.

# Dependencies

This sample project use following libs:
- [BuguRTOS](https://github.com/shkolnick-kun/bugurtos)
- [ArduinoJSON](https://github.com/bblanchon/ArduinoJson)
- [Zhele framework](https://github.com/azhel12/Zhele/tree/feature/cmake_support)

# Requirements:
- cmake
- arm compiler with c++20 support (tested with gcc-arm-none-eabi-13.2)

# Build:
From **build** directory execute commands:
- `cmake -G "Ninja" -DCMAKE_BUILD_TYPE=MinSizeRel ..`
- `cmake --build .`

# Usage:
This firmware allow to control `PA1`, `PA2` and `PA3` GPIOs.

To set PA1 send command:
`{"method": "setpin", "params" : {"port" : "PA", "pin" : 3}}`

To reset PA1 send command:
`{"method": "resetpin", "params" : {"port" : "PA", "pin" : 3}}`

Also, firmware contains task for toggle `PA4` each second.

# Flash and RAM usage:
- Used flash size: **10844 bytes**
- Used RAM size: **1672 bytes**