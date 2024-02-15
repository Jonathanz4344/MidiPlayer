/*
 * echo.c
 *
 *  Created on: Nov 8, 2023
 *      Author: jzmz8
 */

#include "UART.h"
#include "printf.h"
#include "systick.h"

void USART2_IRQHandler() {
    uint8_t ch = USART_Read_Nonblocking(USART2);
    printf("%c", ch);
}
