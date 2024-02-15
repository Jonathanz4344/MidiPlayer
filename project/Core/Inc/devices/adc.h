/*
 * adc.h
 *
 *  Created on: Apr 13, 2022
 *      Author: bruce
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32l4xx.h"

#define ADC_CHANNEL ADC_CHANNEL_5 // A0 on the left connector

void ADC_Init ();
void ADC_Start ();
uint32_t ADC_Read_Value_Blocking ();

#endif /* INC_ADC_H_ */
