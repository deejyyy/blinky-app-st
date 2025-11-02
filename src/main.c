#include "stm32g0xx.h"

void delay(volatile uint32_t n) {
    while(n--) __asm__("nop");
}

int main(void) {
    // Enable GPIOA clock
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

    // Set PA5 to output
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |= (1U << (5 * 2));

    while (1) {
        GPIOA->ODR ^= (1U << 5); // Toggle PA5
        delay(100000);
    }
}