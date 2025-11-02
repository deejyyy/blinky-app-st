cmake_minimum_required(VERSION 3.15)
project(blinky-app-stm32g0b1re C ASM)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

set(CPU_FLAGS "-mcpu=cortex-m0plus -mthumb")
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/STM32G0B1RETx_FLASH.ld")

set(CMAKE_C_FLAGS "${CPU_FLAGS} -Wall -Wextra -Os")
set(CMAKE_EXE_LINKER_FLAGS "${CPU_FLAGS} -T${LINKER_SCRIPT}")

add_executable(blinky
    src/main.c
    src/startup_stm32g0b1xx.s
    src/system_stm32g0xx.c
)

target_include_directories(blinky PRIVATE
    ${CMAKE_SOURCE_DIR}/inc
)

# Optionally, list STM32 HAL sources here if using the full Cube HAL