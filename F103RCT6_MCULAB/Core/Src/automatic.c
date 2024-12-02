/*
 * automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#include "automatic.h"

int countdownX = 0;
int countdownY = 0;

void fsm_automatic() {
	switch (status) {
		case AUTO: {
			if (1) {
				status = GREEN_RED;
				countdownX = greenTime - 1;
				countdownY = redTime - 1;
				updateBufferXLine(countdownX);
				updateBufferYLine(countdownY);
				setTimer(0, greenTime * 1000); // Timer 1
				setTimer(1, 1000);
			}
			break;
		}
		case GREEN_RED: {
			trafficGreenRed();
			if (timer_flag[0] == 1) {
				status = AMBER_RED;
				setTimer(0, yellowTime * 1000); // Timer 1
				countdownX = yellowTime - 1;
			}
			if (timer_flag[1] == 1) {
				//UPDATE DISPLAY
				updateBufferXLine(countdownX);
				updateBufferYLine(countdownY);
				countdownX--;
				countdownY--;
				setTimer(1, 1000); // Timer 2
			}
			if (isButtonPressed(0)) {
//				Check button1_flag == 1, then reset button1_flag = 0
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
			}
			break;
		}
		case AMBER_RED: {
			trafficYellowRed();
			if (timer_flag[0] == 1) {
				status = RED_GREEN;
				setTimer(0, greenTime * 1000); // Timer 1
				countdownX = redTime - 1;
				countdownY = greenTime - 1;
			}
			if (timer_flag[1] == 1) {
				//UPDATE DISPLAY
				updateBufferXLine(countdownX);
				updateBufferYLine(countdownY);
				countdownX--;
				countdownY--;
				setTimer(1, 1000); // Timer 2
			}
			if (isButtonPressed(0)) {
//				Check button1_flag == 1, then reset button1_flag = 0
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
			}
			break;
		}
		case RED_GREEN: {
			trafficRedGreen();
			if (timer_flag[0] == 1) {
				status = RED_AMBER;
				setTimer(0, yellowTime * 1000); // Timer 1
				countdownY = yellowTime - 1;
			}
			if (timer_flag[1] == 1) {
				//UPDATE DISPLAY
				updateBufferXLine(countdownX);
				updateBufferYLine(countdownY);
				countdownX--;
				countdownY--;
				setTimer(1, 1000); // Timer 2
			}
			if (isButtonPressed(0)) {
//				Check button1_flag == 1, then reset button1_flag = 0
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
			}
			break;
		}
		case RED_AMBER: {
			trafficRedYellow();
			if (timer_flag[0] == 1) {
				status = GREEN_RED;
				setTimer(0, greenTime * 1000); // Timer 1
				countdownX = greenTime - 1;
				countdownY = redTime - 1;
			}
			if (timer_flag[1] == 1) {
				//UPDATE DISPLAY
				updateBufferXLine(countdownX);
				updateBufferYLine(countdownY);
				countdownX--;
				countdownY--;
				setTimer(1, 1000); // Timer 2
			}
			if (isButtonPressed(0)) {
//				Check button1_flag == 1, then reset button1_flag = 0
				status = MAN;
				setTimer(2, 10000); // Timer 3
				clearTrafficLight();
			}
			break;
		}
		default: {
			break;
		}
	}
}
