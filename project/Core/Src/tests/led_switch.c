/*
 * ledswitch.c
 *
 *  Created on: Nov 2, 2023
 *      Author: jzmz8
 */

#include "GPIO.h"
#include "LED.h"
#include "printf.h"
#include "systick.h"


void led_switch () {
	GPIO_Init ();
	LED_On(EXTERN_LED);
	while(1) {
		unsigned char flag = (GPIOA->IDR & (1 << 9)) >> 9;
		printf ("%d", flag);
		if (flag) {
			LED_On(EXTERN_LED);
		}
		else {
			LED_Off (EXTERN_LED);
		}

	}
}

