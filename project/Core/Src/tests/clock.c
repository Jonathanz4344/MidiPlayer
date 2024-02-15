/*
 * clock.c
 *
 *  Created on: Nov 7, 2023
 *      Author: jzmz8
 */


// create clock that updates once a second using interrupts


#include "systick.h"
#include "printf.h"

//int count = 0;

//void SysTick_Handler() {
//	count++;
//
//}

//void clock() {
//	init_systick();
//	int seconds = 0;
//	while(1) {
//		if (count == 1000){
//			seconds++;
//			int hours = seconds / 3600;
//			int minutes = seconds / 60 % 60;
//			printf("%02d:%02d:%02d\r", hours, minutes, seconds % 60);
//			count = 0;
//		}
//	}
//
//}
