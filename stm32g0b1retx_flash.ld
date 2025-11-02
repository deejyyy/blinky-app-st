/* Minimal linker script for STM32G0B1RE (adjust as needed) */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 32K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

ENTRY(Reset_Handler)

SECTIONS
{
    .text : {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        KEEP(*(.init))
        KEEP(*(.fini))
    } > FLASH

    .data : AT (ADDR(.text) + SIZEOF(.text)) {
        *(.data*)
    } > RAM

    .bss : {
        *(.bss*)
        *(COMMON)
    } > RAM

    .stack :
    {
        . = ALIGN(8);
        _stack_start = .;
        . = . + 0x400;
        _stack_end = .;
    } > RAM
}