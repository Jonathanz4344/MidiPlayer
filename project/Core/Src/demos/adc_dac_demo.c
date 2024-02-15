/*
 * adc_example.c
 *
 *  Created on: Apr 13, 2022
 *      Author: bruce
 */

#include "adc.h"
#include "dac.h"
#include "adc_demo.h"


uint8_t one_second_elapsed = FALSE;
uint32_t counter = 0;

void Error_Handler () {
	// Add error handler here if desired
}

// Systic interrupt handler
void SysTick_Handler() {
	static uint32_t counter = 0; // that counts up to 1000
	counter++;
	if (counter == 1000) {
		one_second_elapsed = TRUE;
		counter = 0;
	}
}

static void init_systick()
{
	// Replace with your init_systick
}

void run_adc_dac_demo()
{
	uint16_t counter = 0;
	// printf ("Start!\n\r");
	init_systick();
	DAC_Init ();
	ADC_Init ();

	DAC_Start ();

	uint32_t adc_value = 0;

	while (1)
	{
		if (one_second_elapsed /*&& (old_adc_value != new_adc_value)*/) {
			ADC_Start ();
			adc_value = ADC_Read_Value_Blocking ();
			// printf ("ADC read: 0x%x\n\r", (unsigned int)adc_value);
			// Rediculous way to eliminate warning. Delete this line when printf is working.
			adc_value = adc_value;


			DAC_Set_Value ((0x100 * counter) % 0x1000);
			counter++;
			one_second_elapsed = FALSE;
		}

	}
}

