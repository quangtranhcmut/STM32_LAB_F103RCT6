/*
 * manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#include "manual.h"

int mode = 0;
int redValue = 0;
int yellowValue = 0;
int greenValue = 0;

void fsm_manual() {
	switch(status) {
		case MAN: {
			updateBufferXLine(mode);
			updateBufferYLine(0);
			if (timer_flag[3] == 1) {
				setTimer(3, 500); // Timer 4
				blinkAllLed(); // Blink 2Hz
			}
			if (isButtonPressed(0)) {
				status = MODE2;
				mode = 2;
				// Save original values
				redValue = redTime;
				yellowValue = yellowTime;
				greenValue = greenTime;
				updateBufferXLine(mode);
				updateBufferYLine(redTime);
				clearTrafficLight();
				break;
			}
			// Update: When BTN2 pressed, reset button_flag[1] and do nothing
			if (isButtonPressed(1)) { // BTN2 pressed, reset button_flag[1]
				break;
			}
			break;
		}
		case MODE2: {
			if (timer_flag[3] == 1) {
				setTimer(3, 500); // Timer 4
				blinkRedLed(); // Blink 2Hz
			}
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MODE3;
				mode = 3;
				// Adjust Time to the original, not save the updated value
				setRedTime(redValue);
				setYellowTime(yellowValue);
				setGreenTime(greenValue);
				updateBufferXLine(mode);
				updateBufferYLine(yellowTime);
				clearTrafficLight();
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updateRedTime();
				updateBufferYLine(redTime);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
				mode = 0;
				break;
			}
			break;
		}
		case MODE3: {
			if (timer_flag[3] == 1) {
				setTimer(3, 500); // Timer 4
				blinkYellowLed(); // Blink 2Hz
			}
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MODE4;
				mode = 4;
				// Adjust Time to the original, not save the updated value
				setRedTime(redValue);
				setYellowTime(yellowValue);
				setGreenTime(greenValue);
				updateBufferXLine(mode);
				updateBufferYLine(greenTime);
				clearTrafficLight();
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updateYellowTime();
				updateBufferYLine(yellowTime);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
				mode = 0;
				break;
			}
			break;
		}
		case MODE4: {
			if (timer_flag[3] == 1) {
				setTimer(3, 500); // Timer 4
				blinkGreenLed(); // Blink 2Hz
			}
			if (isButtonPressed(0)) { // BTN1 pressed, update status and discard value
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
				mode = 0;
				// Adjust Time to the original, not save the updated value
				setRedTime(redValue);
				setYellowTime(yellowValue);
				setGreenTime(greenValue);
				updateBufferXLine(mode);
				updateBufferYLine(0);
				break;
			}
			if (isButtonPressed(1)) { // BTN2 pressed, update value
				updateGreenTime();
				updateBufferYLine(greenTime);
				break;
			}
			if (isButtonPressed(2)) { // BTN3 pressed, save the value -> update Time
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
				mode = 0;
				break;
			}
			break;
		}
		default: {
			break;
		}
	}
}
