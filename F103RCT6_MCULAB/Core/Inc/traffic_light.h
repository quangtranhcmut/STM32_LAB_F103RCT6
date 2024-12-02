/*
 * traffic_light.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"

extern int redTime;
extern int yellowTime;
extern int greenTime;

void trafficGreenRed();
void trafficYellowRed();
void trafficRedGreen();
void trafficRedYellow();

void setRedTime(int redValue);
void setYellowTime(int yellowValue);
void setGreenTime(int greenValue);

void updateRedTime();
void updateGreenTime();
void updateYellowTime();

void blinkRedLed();
void blinkYellowLed();
void blinkGreenLed();

void blinkAllLed();
void clearTrafficLight();
void blinkDot();

#endif /* INC_TRAFFIC_LIGHT_H_ */
