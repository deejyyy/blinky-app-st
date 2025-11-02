cmake_minimum_required(VERSION 3.15)
project(blinky-app-st C ASM)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CMAKE_BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

set(CPU_FLAGS "-mcpu=cortex-m0plus -mthumb -fno-exceptions -fno-unwind-tables")
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/stm32g0b1retx_flash.ld -nostdlib -nostartfiles")

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

# Post-build: convert ELF to BIN
add_custom_command(TARGET blinky POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary $<TARGET_FILE:blinky> ${CMAKE_BINARY_DIR}/blinky.bin
    COMMENT "Generating blinky.bin from blinky.elf"
)