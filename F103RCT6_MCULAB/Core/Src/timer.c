/*
 * timer.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Thảo Quảng
 */
#include "timer.h"

int TIMER_CYCLE = 1;
void setTimer(int index, int counter){
	timer_flag[index] = 0;
	timer_counter[index] = counter / TIMER_CYCLE;
}

int timer_flag[10];
int timer_counter[10];
void timerRun(){
	for (int i = 0; i < 10; i++) {
		if (timer_counter[i] >= 0) {
			timer_counter[i]--;
			if (timer_counter[i] <= 0) {
				timer_flag[i] = 1;
			}
		}
	}
}

