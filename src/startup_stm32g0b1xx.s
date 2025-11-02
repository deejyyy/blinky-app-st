.syntax unified
.cpu cortex-m0plus
.thumb

.global Reset_Handler
.global _estack

.section .isr_vector, "a", %progbits
.type isr_vector, %object
isr_vector:
    .word   _estack
    .word   Reset_Handler
    .word   0 // NMI_Handler
    .word   0 // HardFault_Handler
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // SVC_Handler
    .word   0 // Reserved
    .word   0 // Reserved
    .word   0 // PendSV_Handler
    .word   0 // SysTick_Handler

    // Interrupts...

.section .text.Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    bl  SystemInit
    bl  main
1:  b   1b