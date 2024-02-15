#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"

void LED_Init(void);

void LED_Off(void);
void LED_On(void);
void LED_Toggle(void);

#endif /* __NUCLEO476_LED_H */
