///*
// * demo.c
// *
// *  Created on: Feb 14, 2021
// *      Author: larry kiser
// *  Updated on: Sept 6, 2021
// *      Author: Mitesh Parikh
// */
//
//#include <stdio.h>
//#include <string.h>
//
//// Custom Include files
//#include "LED.h"
//#include "UART.h"
//#include "demo.h"
//#include "stm32l4xx.h"
//#include "systick.h"
//#include "systick.h"
//
//
//// This function is to create a delay by consuming CPU cycle on counter
//static void delay_loop( int value )
//{
//	// spin loop consuming CPU to spend time.
//	for (int i = 0; i < value; i++);
//}
//
//// This function is to print counter on UART port and toggle LED
//static void demo_of_UART_print(int counter){
//	int n ;
//	uint8_t buffer[BUFFER_SIZE];
//
//	n = sprintf((char *)buffer, "counter = %d\r\n", counter);
//	USART_Write(USART2, buffer, n);
//
//	delay_loop( 8000000 ) ;	// comment this out when you are ready to test delay_systick
//	// delay_systick() ;	// enable this when you are ready to test
//
//	// Toggle LED
//	LED_Toggle(5);
//}
//
//void run_demo(){
//
//	int counter = 0;
//
//	init_systick();
//
//	// Run a loop to print counter value on UART port
//	while (1)
//	{
//		//demo_of_printf_scanf();
//		demo_of_UART_print(counter);
//		counter++;
//
//		delay_systick();
//
//		// Toggle LED
//		LED_Toggle(5);
//	}
//}

