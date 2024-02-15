#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"

#define EXTERN_LED (5)

void LED_Init(uint8_t pin);

void LED_Off(uint8_t pin);
void LED_On(uint8_t pin);
void LED_Toggle(uint8_t pin);

#endif /* __NUCLEO476_LED_H */
