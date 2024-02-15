#include "LED.h"


//******************************************************************************************
// User LED = LD2 Green LED = PA.5
//******************************************************************************************
#define LED_PIN 5

void LED_Init(uint8_t pin){
	
	// Enable the peripheral clock of GPIO Port	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;	

	// GPIO Mode: Input(00), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOA->MODER &= ~(3U<<(2*pin));
	GPIOA->MODER |= 1U<<(2*pin);      //  Output(01)
	
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOA->OSPEEDR &= ~(3U<<(2*pin));
	GPIOA->OSPEEDR |=   3U<<(2*pin);  // High speed
	
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOA->OTYPER &= ~(1U<<pin);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOA->PUPDR   &= ~(3U<<(2*pin));  // No pull-up, no pull-down
	
}

//******************************************************************************************
// Turn LED On
//******************************************************************************************
void LED_On(uint8_t pin){
	GPIOA->ODR |= (1UL<<pin);
}

//******************************************************************************************
// Turn LED Off
//******************************************************************************************
void LED_Off(uint8_t pin){
	GPIOA->ODR &= ~(1UL<<pin);
}

//******************************************************************************************
// Toggle LED 
//******************************************************************************************
void LED_Toggle(uint8_t pin){
	GPIOA->ODR ^= (1UL<<pin);
}
