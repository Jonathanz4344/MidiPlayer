/*
 * song.h
 *
 *  Created on: May 14, 2022
 *      Author: Bruce Herring
 *
 *  DO NOT MODIFY
 */

#ifndef INC_SONG_H_
#define INC_SONG_H_

#include <stdint.h>

// A little struct to help make tracking songs easier.
typedef struct {
	unsigned char* p_song;
	unsigned int size;
}song;

song get_song (uint8_t);

#endif /* INC_SONG_H_ */
