/*
 * button.h
 *
 *  Created on: Oct 25, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NUM_BUTTONS 10
#define NORMAL_STATE RESET
#define PRESSED_STATE SET

extern int KeyReg0[NUM_BUTTONS];
extern int KeyReg1[NUM_BUTTONS];
extern int KeyReg2[NUM_BUTTONS];
extern int KeyReg3[NUM_BUTTONS];

extern int TimeOutForKeyPress[NUM_BUTTONS];
extern int button_pressed[NUM_BUTTONS];
extern int button_long_pressed[NUM_BUTTONS];
extern int button_flag[NUM_BUTTONS];

void initButtons(void);
int isButtonPressed(int buttonIndex);
int isButtonLongPressed(int buttonIndex);
void subKeyProcess(int buttonIndex);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
