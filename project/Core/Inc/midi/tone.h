/*
 * tone.h
 *
 *  Created on: May 14, 2022
 *      Author: bruce
 */

#ifndef INC_TONE_H_
#define INC_TONE_H_

#include "dac.h"
#include "song.h"

/**
 * SysTick handler. Since tones are controlled by software, the SysTick timer
 * must be used accurately manage the times.
 */
void SysTick_Handler();

/**
 * Accessor for the counter. Useful for knowing what the current "time" is
 * in the system.
 */
uint32_t get_counter ();

void reset_counter ();

/**
 * Utility function that converts a frequency into a duration.
 */
uint32_t hertz_to_duration (float hertz);

/**
 * Adds a tone to be played.
 */
uint8_t add_tone (uint8_t note, uint8_t velocity);

/**
 * Removes a tone from the current group of tones that can be played.
 */
uint8_t remove_tone (uint8_t note);

void start_midi(song midi);
void play_midi();



/**
 * Starts playing any tones that have been added.
 */


#endif /* INC_TONE_H_ */
