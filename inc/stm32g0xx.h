#ifndef STM32G0XX_H
#define STM32G0XX_H

#include <stdint.h>

#define RCC_BASE     (0x40021000UL)
#define GPIOA_BASE   (0x50000000UL)

#define RCC          ((RCC_TypeDef *) RCC_BASE)
#define GPIOA        ((GPIO_TypeDef *) GPIOA_BASE)

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t RESERVED0[1];
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    volatile uint32_t IOPRSTR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t IOPENR;
    // ... add additional registers as needed
} RCC_TypeDef;

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    // ... add additional registers as needed
} GPIO_TypeDef;

#define RCC_IOPENR_GPIOAEN (1U << 0)

#endif // STM32G0XX_H