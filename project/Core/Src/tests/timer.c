/*
 * timer.c
 *
 *  Created on: Oct 3, 2023
 *      Author: jzmz8
 */
#include "systick.h"
#include "printf.h"

struct Register* init_systtick () {

	struct Register* Registers = (struct Register*) 0xE000E010;
	printf("%x\r\n", Registers);
	Registers->RVR = 7999999; // (99999 +1) / 8000000 sec timer sets reload timer to 100 000
	Registers->CSR = 0;
	Registers->CSR |= 1 << 2; //set clk source
	Registers->	CSR |= 1 << 0; // set bit 0 to turn on
//	Registers->CSR = Registers->CSR | (1 << 0); // set bit 0 to turn on

	return Registers;


}

void run_timer () {
	struct Register* Registers = init_systtick ();
	while (1)
		printf("%d\r\n", (unsigned int)Registers->CVR);
}


void clock () {
	// print seconds since clock started, once a second
	struct Register* Registers = init_systtick ();
	unsigned int seconds = 0;
	int count = 0;
	while (1) {
		if ((Registers->CSR >> 16) != 0){
			count++;
			if(count == 10){
				count = 0;
				seconds++;
				printf("%d\r\n", seconds);
			}
		}
	}

}
