/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "traffic_light.h"
#include "button.h"
#include "7seg.h"
#include "timer.h"

extern int status;

#define INIT 0
#define AUTO 1
#define MAN 2

#define GREEN_RED 11
#define	AMBER_RED 12
#define	RED_GREEN 13
#define	RED_AMBER 14

#define MODE2 21
#define MODE3 22
#define MODE4 23

void fsm_setting();

#endif /* INC_GLOBAL_H_ */
