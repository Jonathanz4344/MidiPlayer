/*
 * project1.c
 *
 *  Created on: Oct 24, 2023
 *      Author: jzmz8
 */

#include "project1.h"
#include "printf.h"
#include "UART.h"
#include "LED.h"
#include <string.h>
#include "song.h"
#include "systick.h"
#include "GPIO.h"
#include "stm32l4xx_hal.h"
#include "dac.h"
#include "tone.h"


#define NUM_SONGS 5
static uint8_t currentSongIndex = 0;
static int midiPlaybackStarted = 0;


volatile int localModeEnabled = 0;
static int playPauseState = 0; // 0 represents pause, 1 represents play

void extractMetadataFromMIDI(const unsigned char *midiData, size_t midiSize) {
	char songTitle[100] = "";
	char copyright[100] = "";
	uint32_t tempo = 0;

	int foundTitle = 0;
	int foundCopyright = 0;
	int foundTempo = 0;

	for (size_t i = 0; i < midiSize - 6; i++) {
		if (midiData[i] == 0x4D && midiData[i + 1] == 0x54 && midiData[i + 2] == 0x72 && midiData[i + 3] == 0x6B) {
			// This is the track chunk, and metadata should be present

			// Search for relevant events
			while (i < midiSize - 6) {
				// Look for metadata events
				if (midiData[i] == 0xFF) {
					uint8_t eventType = midiData[i + 1];
					uint8_t eventLength = midiData[i + 2];

					if (eventType == 0x03 && !foundTitle) {
						// Track Name Event (Song Title)
						strncpy(songTitle, (char *)(midiData + i + 3), eventLength);
						songTitle[eventLength] = '\0';
						foundTitle = 1;
					} else if (eventType == 0x02 && !foundCopyright) {
						// Copyright Notice Event
						strncpy(copyright, (char *)(midiData + i + 3), eventLength);
						copyright[eventLength] = '\0';
						foundCopyright = 1;
					} else if (eventType == 0x51 && !foundTempo) {
						// Tempo Event
						tempo = convert_to_uint32((uint8_t *)(midiData + i + 3));
						foundTempo = 1;
					}
					// Move the index past this event
					i += (3 + eventLength);
				} else {
					// Skip non-metadata events
					i++;
				}
			}
		}
	}
	// Display the extracted information
	printf("Title: %s\r\n", songTitle);
	printf("Copyright: %s\r\n", copyright);
	printf("Tempo: %lu\r\n", tempo);
}

void displaySongInfo(song currentSong) {
	// Extract song data (song.p_song) and size (song.size) from the 'currentSong' structure.
	unsigned char *songData = currentSong.p_song;
	size_t songSize = currentSong.size;

	// Display the extracted metadata
	extractMetadataFromMIDI(songData, songSize);
}

void printHelp(){
	printf("***REMOTE LED CONTROL MENU***\r\n");
	printf("Available User Commands\r\n");
	printf("NEXT - Show next song info\r\n");
	printf("PLAY - Play the song (LED on)\r\n");
	printf("PAUSE - Pause the song (LED Flash)\r\n");
	printf("STOP - Stop the song (LED off)\r\n");
}

void toggleCommand(char* command) {
	if (strcmp(command, "PLAY") == 0) {
		// Turn on the LED
		LED_On(EXTERN_LED);
		flashEnabled = 0;
		DAC_Set_Value(4000);
		delay_systick_ms(200);
		DAC_Set_Value(0);
	} else if (strcmp(command, "STOP") == 0) {
		// Turn off the LED
		LED_Off(EXTERN_LED);
		flashEnabled = 0;
		DAC_Set_Value(4000);
		delay_systick_ms(200);
		DAC_Set_Value(0);
	} else if (strcmp(command, "HELP") == 0) {
		printHelp();
	} else if (strcmp(command, "PAUSE") == 0) {
		flashEnabled = 1;
		DAC_Set_Value(4000);
		delay_systick_ms(200);
		DAC_Set_Value(0);
	} else if (strcmp(command, "NEXT") == 0) {
		if (currentSongIndex >= NUM_SONGS) {
			// Wrap around to the first song
			currentSongIndex = 0;
		}
		song currentSong = get_song(currentSongIndex);
		displaySongInfo(currentSong);
		currentSongIndex++;
		DAC_Set_Value(4000);
		delay_systick_ms(200);
		DAC_Set_Value(0);
	} else {
		printf("Invalid command\r\n");
		flashEnabled = 0;
	}
}

void handleBackspace(char* input, int* length) {
	if (*length > 0) {
		(*length)--;
		input[*length] = '\0';
		// Send backspace and space characters to erase the last character
		printf("\b \b");
	}
}

void echoWords(char* command, int maxLength) {
	int index = 0;
	int count = 0;

	while (!localModeEnabled) {
		char c = USART_Read_Nonblocking(USART2);

		if (c != 0) {
			if (c == '\n' || c == '\r') {
				command[index] = '\0';
				break;
			} else if ( c == '\b') {
				handleBackspace(command, &index);
			}
			else {
				if (index < maxLength - 1) {
					command[index] = c;
					command[index+1] = '\0';
					index++;
					printf("%c", c);
				}
			}
		}
		if(flashEnabled) {
//			init_systick();
			count++;
			if (count == 1000) {
				LED_Toggle(EXTERN_LED);
				count = 0;
			}
			delay_systick(10);
		}
		else {
			count = 0;
		}
	}
	printf("\r\n");
}

void enterLocalMode() {
	localModeEnabled = 1;
	printf("***MANUAL OVERRIDE MODE ACTIVE***\r\n");
	LED_Off(EXTERN_LED);
}

void exitLocalMode() {
	localModeEnabled = 0;
	LED_Off(EXTERN_LED);
	flashEnabled = 0;
	currentSongIndex = 0;
	printf("***REMOTE MODE ACTIVE***\r\n");
}

uint32_t counter = 0;
uint32_t startTime;
uint32_t endTime;
uint8_t button_pressed = 0;
uint32_t button_pressed_duration = 0;

void handleS1Button() {
	DAC_Set_Value(4000);//	init_systick();
	startTime = get_systick_count_ms();
	delay_systick(100);
	button_pressed = 1;

	// Wait for the button to be released
	while (HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin));
	endTime = get_systick_count_ms();
	button_pressed_duration = endTime - startTime;
	counter++;
	DAC_Set_Value(0);
}


void project1_main() {
	init_systick();
	GPIO_Init();
	UART2_Init();
	printHelp();
	DAC_Init();
	DAC_Start();


	char command[50];
	uint32_t flash_count = 0;

	while(1) {
		NVIC_DisableIRQ(USART2_IRQn);


		if (!localModeEnabled) {
			echoWords(command, sizeof(command));
			toggleCommand(command);
		}
		else // Manual Mode
		{
			if(button_pressed) // there is a press
			{
				if(button_pressed_duration >= 1000) // stop
				{
					printf("STOP\r\n");
					LED_Off(EXTERN_LED);
					counter = 0;
				}
				else // duration < 1000
				{
					while((counter == 1) && (get_systick_count_ms() - startTime < 1000));

					if(counter == 1) // single press
					{
						if (playPauseState == 0) {
							playPauseState = 1;
							printf("PLAY\r\n");
							LED_On(EXTERN_LED);
							if (!midiPlaybackStarted) {
                            start_midi(get_song(currentSongIndex - 1));
                            midiPlaybackStarted = 1;
							}
							play_midi();
						} else {
							playPauseState = 0;
							printf("PAUSE\r\n");
							LED_Off(EXTERN_LED);
						}
					}
					else // double press
					{
						if (currentSongIndex >= NUM_SONGS) {
							currentSongIndex = 0;
						}
						song currentSong = get_song(currentSongIndex);
						displaySongInfo(currentSong);
						currentSongIndex++;
					}
					counter = 0;
				}
				button_pressed = 0;
			}
			else
			{
				// no button press do nothing
			}

			if(playPauseState == 0)
			{
				flash_count++;
				if (flash_count >= 500) {
					LED_Toggle(EXTERN_LED);
					flash_count = 0;
				}
				delay_systick(1);
			}
			else
			{
				flash_count = 0;
			}

		}
	}
}







