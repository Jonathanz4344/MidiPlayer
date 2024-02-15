//#include "LED.h"
//#include "UART.h"
//#include "systick.h"
//#include "printf.h"
//
//void hw4_run() {
//
//	init_systick();
//	int count = 0;
//    while (1) {
//		 count++;
//		 char ch = USART_Read_Nonblocking (USART2);
//		 if (ch != 0) {
//			 printf ("%c", ch);
//		 }
//		 // change delay to only count to 1
//		 delay_systick();
//		 // count to 10, then toggle LED
//		 if (count == 1000) {
//			 LED_Toggle (EXTERN_LED);
//			 count = 0;
//		 }
//    }
//}





