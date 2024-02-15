/*
 * systick.c
 *
 *  Created on: Oct 12, 2023
 *      Author: jzmz8
 */


#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_
#include <stdint.h>
#define SYSTICK_CTRL_ENABLE (1U << 0)
#define SYSTICK_CTRL_TICKINT (1U << 1)

#include "systick.h"

struct Register {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;

};

static struct Register *SysTick = (struct Register *)0xE000E010;
// This function is to Initialize SysTick registers
void init_systick() {
    SysTick->RVR = 79999; // 1ms timer
    SysTick->CSR = 0;
    SysTick->CSR |= 1 << 16;
    SysTick->CSR |= 1 << 2;
    SysTick->CSR |= 1 << 1;
    SysTick->CSR |= 1 << 0;
}
uint32_t systic_count = 0;

void SysTick_Handler() {
	systic_count++;

}

// This fuction is to create delay using SysTick timer counter
void delay_systick(uint32_t d)
{
	// Using the SysTick global structure pointer do the following:
	// Create a for loop that loops 10 times
	// Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
	// register in a loop. When that bit is set exit this inner loop
	// to do another pass in the outer loop of 10.

	 for (int i = 0; i < d; i++) {
	        while (!(SysTick->CSR & (1 << 16)));
	            // Wait for the COUNTFLAG bit in the CTRL (CSR) to be set.
	 }
}

uint32_t get_systick() {
	return SysTick->CVR;
}

uint32_t get_systick_count_ms()
{
	return systic_count;
}

void delay_systick_ms(uint32_t ms) {
    uint32_t start = get_systick();
    uint32_t target = start + ms;

    while (get_systick() < target);
}

uint16_t convert_to_uint16(uint8_t *p_value) {
    return (p_value[0] << 8) + p_value[1];
}

uint32_t convert_to_uint24 (uint8_t* p_value) {
    return (p_value[0] << 16) + (p_value[1] << 8) + p_value[2];
}

uint32_t convert_to_uint32(uint8_t *p_value) {
//    return (p_value[0] << 24) | (p_value[1] << 16) | (p_value[2] << 8) | p_value[3];
	return (p_value [0] << 24) + (p_value [1] << 16) + (p_value [2] << 8) + p_value [5];
}

#endif /* INC_SYSTICK_H_ */
