cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stm32_gcc.cmake)
set (CMAKE_CXX_STANDARD 20)

project(expander CXX C ASM)

stm32_fetch_cmsis(F0)

find_package(CMSIS COMPONENTS STM32F0 REQUIRED)

# Add zhele
include(FetchContent)
FetchContent_Declare(Zhele
    GIT_REPOSITORY https://github.com/azhel12/Zhele.git
    GIT_TAG        cmake_0.1
)
FetchContent_MakeAvailable(Zhele)

# Initialize and add BuguRTOS
set(BGRT_CONFIG_DIR "config/")
set(BGRT_ARCH "cm0")
include(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/bugurtos/bugurtos.cmake)

# Add ArduinoJson
include(FetchContent)
FetchContent_Declare(ArduinoJson
    GIT_REPOSITORY https://github.com/bblanchon/ArduinoJson.git
    GIT_TAG        v6.21.3
)
FetchContent_MakeAvailable(ArduinoJson)

# Project sources
set(PROJECT_SOURCES
    src/main.cpp
    src/int_handlers.cpp
)

add_executable(expander ${PROJECT_SOURCES})

target_link_libraries(expander zhele::zhele CMSIS::STM32::F030x6 bugurtos_kernel bugurtos_native_api ArduinoJson STM32::NoSys STM32::Nano)
target_compile_options(expander PRIVATE -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections)
target_compile_definitions(expander PRIVATE
    ARDUINOJSON_DECODE_UNICODE=0
    ARDUINOJSON_USE_DOUBLE=0
    ARDUINOJSON_USE_LONG_LONG=0)

# Custom LD with stack=0x200, heap=0
stm32_add_linker_script(expander PRIVATE src/f030f0.ld)

stm32_print_size_of_target(expander)
stm32_generate_binary_file(expander)
