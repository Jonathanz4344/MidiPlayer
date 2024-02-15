/*
 * reader.c
 *
 *  Created on: Sep 26, 2023
 *      Author: jzmz8
 */

#include "reader.h"
#include "UART.h"
#include "printf.h"


static char BUFFER [128];

char* readline () {
	int index = 0;
	char ch = 0;
	while (ch != '\r') {
		ch = USART_Read (USART2);
		BUFFER [index] = ch;
		index++;
	}
	BUFFER [index -1] = 0;

	return BUFFER;
}

void run () {
	// Read one character
	while(1){
		char* line = readline ();
		// Print that character on it's own line
		printf("%s\r\n", line);
	}

}
