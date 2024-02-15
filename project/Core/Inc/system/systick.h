/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_
#include <stdint.h>

struct Register {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

// This function is to Initialize SysTick registers
void init_systick(void);

void delay_systick(uint32_t d);

void delay_systick_ms(uint32_t ms);

uint32_t get_systick(void);

uint32_t get_systick_count_ms();

uint32_t convert_to_uint32(uint8_t *p_value);

#endif /* INC_SYSTICK_H_ */



