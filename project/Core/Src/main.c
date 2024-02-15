// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files

#include <string.h>
#include <stdio.h>

#include "LED.h"
#include "UART.h"

#include "printf.h"
#include "SysClock.h"

#include "clock.h"
#include "hello_world.h"
#include "led_switch.h"
#include "reader.h"
#include "sqr_wave.h"
#include "hw8.h"

#include "demo.h"
#include "hw4.h"
#include "project1.h"
#include "stm32l4xx_hal.h"



int flashEnabled = 0;

int main(void) {
    // Initialization code
	HAL_Init();
    System_Clock_Init(); // Set System Clock = 80 MHz
    LED_Init(EXTERN_LED);
    UART2_Init();



    project1_main();
//    run_wave(1);
    parseDelayMain();

}








