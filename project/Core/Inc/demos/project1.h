/*
 * project1.h
 *
 *  Created on: Oct 24, 2023
 *      Author: jzmz8
 */

#ifndef INC_DEMOS_PROJECT1_H_
#define INC_DEMOS_PROJECT1_H_

extern int flashEnabled;
extern volatile int localModeEnabled;
extern volatile int s1ButtonPressed;

void printHelp(void);
void pauseCommand();
void toggleCommand(char* command);
void echoWords(char* command, int maxLength);
void project1_main(void);
void enterLocalMode(void);
void exitLocalMode(void);
void handleS1Button();

#endif /* INC_DEMOS_PROJECT1_H_ */
