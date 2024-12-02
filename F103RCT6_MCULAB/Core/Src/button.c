/*
 * button.c
 *
 *  Created on: Oct 25, 2024
 *      Author: Thảo Quảng
 */

#include "button.h"

//#define NUM_BUTTONS 10
//#define NORMAL_STATE 1
//#define PRESSED_STATE 0

int KeyReg0[NUM_BUTTONS];
int KeyReg1[NUM_BUTTONS];
int KeyReg2[NUM_BUTTONS];
int KeyReg3[NUM_BUTTONS];

int TimeOutForKeyPress[NUM_BUTTONS];
int button_pressed[NUM_BUTTONS];
int button_long_pressed[NUM_BUTTONS];
int button_flag[NUM_BUTTONS];

void initButtons() {
    for (int i = 0; i < NUM_BUTTONS; i++) {
        KeyReg0[i] = NORMAL_STATE;
        KeyReg1[i] = NORMAL_STATE;
        KeyReg2[i] = NORMAL_STATE;
        KeyReg3[i] = NORMAL_STATE;
        TimeOutForKeyPress[i] = 500;
        button_pressed[i] = 0;
        button_long_pressed[i] = 0;
        button_flag[i] = 0;
    }
}

int isButtonPressed(int buttonIndex) {
    if (button_flag[buttonIndex] == 1) {
        button_flag[buttonIndex] = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int buttonIndex) {
    if (button_long_pressed[buttonIndex] == 1) {
        button_long_pressed[buttonIndex] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int buttonIndex) {
    button_flag[buttonIndex] = 1;
}

void getKeyInput() {
	for (int buttonIndex = 0; buttonIndex < NUM_BUTTONS; buttonIndex++) {
		KeyReg2[buttonIndex] = KeyReg1[buttonIndex];
		KeyReg1[buttonIndex] = KeyReg0[buttonIndex];
	}

    KeyReg0[0] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
    KeyReg0[1] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
    KeyReg0[2] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
    KeyReg0[3] = HAL_GPIO_ReadPin(WKUP_GPIO_Port, WKUP_Pin);
//    KeyReg0[4] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);
//    KeyReg0[5] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);
//    KeyReg0[6] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);
//	  KeyReg0[7] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);
//    KeyReg0[8] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);
//    KeyReg0[9] = HAL_GPIO_ReadPin(GPIO_Port, GPIO_Pin);

    for (int buttonIndex = 0; buttonIndex < NUM_BUTTONS; buttonIndex++) {
		if ((KeyReg1[buttonIndex] == KeyReg0[buttonIndex]) && (KeyReg1[buttonIndex] == KeyReg2[buttonIndex])) {
			if (KeyReg2[buttonIndex] != KeyReg3[buttonIndex]) {
				KeyReg3[buttonIndex] = KeyReg2[buttonIndex];
				if (KeyReg3[buttonIndex] == PRESSED_STATE) {
					TimeOutForKeyPress[buttonIndex] = 500;
					button_flag[buttonIndex] = 1;
				}
			}
			else {
				TimeOutForKeyPress[buttonIndex]--;
				if (TimeOutForKeyPress[buttonIndex] == 0) {
					TimeOutForKeyPress[buttonIndex] = 500;
					if (KeyReg3[buttonIndex] == PRESSED_STATE) {
						button_flag[buttonIndex] = 1;
					}
				}
			}
		}
    }
}





