/*
 * gpio.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */


/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"
#include <stdbool.h>
#include "stm32l4xx.h"

// External Global Variables that we will need access to


/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = S1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(S1_GPIO_Port, &GPIO_InitStruct);

	/* EXTI15_10_IRQn interrupt init*/
	// Note you will have to add EXTI15_10_IRQn Interrupt handler function as well
	// This is the interrupt handler for the blue button


	/* EXTI9_5_IRQn interrupt init*/
	// Note you will have to add EXTI9_15_IRQn Interrupt handler function as well
	// This is the interrupt handler for the external buttons (S1)
}

