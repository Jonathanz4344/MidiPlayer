/*
 * hw8.c
 *
 *  Created on: Nov 29, 2023
 *      Author: jzmz8
 */
#include <stdint.h>
#include <printf.h>

uint32_t parseDelay (uint8_t* delay) {
    int i = 0;
    uint8_t curr = delay [i];
    uint32_t parsed_delay = 0;
    while (curr >> 7) { // More
        parsed_delay += (curr & 0x7F) << 7;
        curr = delay [++i];
    }
    parsed_delay += curr & 0x7F;

    return parsed_delay;
}

// Test values from homework #9
int parseDelayMain() {
    uint8_t testDelay1[] = {0x3B, 0x80, 0x27, 0x00};
    uint8_t testDelay2[] = {0x83, 0x18, 0x91, 0x54, 0x64};
    uint8_t testDelay3[] = {0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12};
    uint8_t testDelay4[] = {0x90, 0x82, 0x93, 0x64, 0xD3, 0x89};

    uint32_t result1 = parseDelay(testDelay1);
    uint32_t result2 = parseDelay(testDelay2);
    uint32_t result3 = parseDelay(testDelay3);
    uint32_t result4 = parseDelay(testDelay4);

    // Print results for verification
    printf("Result 1: %lu\n", result1);
    printf("Result 2: %lu\n", result2);
    printf("Result 3: %lu\n", result3);
    printf("Result 4: %lu\n", result4);

    return 0;
}
