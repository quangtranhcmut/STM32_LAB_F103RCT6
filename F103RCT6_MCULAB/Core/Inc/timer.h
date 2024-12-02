/*
 * timer.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int timer_flag[];
extern int timer_counter[];
extern int TIMER_CYCLE;
void setTimer(int index, int counter);
void timerRun();

#endif /* INC_TIMER_H_ */
