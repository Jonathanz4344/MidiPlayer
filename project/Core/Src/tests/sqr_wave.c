/*
 * sqr_wave.c
 *
 *  Created on: Nov 28, 2023
 *      Author: jzmz8
 */

#include "tone.h"
#include "printf.h"
#include "systick.h"

//print 1 when the wave is high and 0 when the wave is low
//run for a 1 second frequency wave
//verify it works in your terminal


//frequency is in Hertz

extern uint32_t systic_count;
void run_wave (int frequency)
{
//	init_systick();
	DAC_Init();
	DAC_Start();
	uint32_t duration = hertz_to_duration(frequency);



	// replace prints with actual power setting
	while(1)
	{
		if (systic_count % duration < (duration >> 1)){
			// printf ("1");
			DAC_Set_Value(2000); // max 4095
		}
		else
		{
			// printf("0");
			DAC_Set_Value(0);
		}
	}
}



