///*
// * s_button.c
// *
// *  Created on: Oct 25, 2024
// *      Author: Thảo Quảng
// */
//
//
//#include "s_button.h"
//int KeyReg0_1 = NORMAL_STATE1;
//int KeyReg1_1 = NORMAL_STATE1;
//int KeyReg2_1 = NORMAL_STATE1;
//int KeyReg3_1 = NORMAL_STATE1;
//
//int TimeOutForKeyPress_1 =  500;
//int button1_pressed = 0;
//int button1_long_pressed = 0;
//int button1_flag = 0;
//
//int isButton1Pressed(){
//	if(button1_flag == 1){
//		button1_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButton1LongPressed(){
//	if(button1_long_pressed == 1){
//		button1_long_pressed = 0;
//		return 1;
//	}
//	return 0;
//}
//
//void subKeyProcess1(){
//	//TODO
//	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
//	button1_flag = 1;
//}
//
//void getKeyInput1(){
//	KeyReg2_1 = KeyReg1_1;
//	KeyReg1_1 = KeyReg0_1;
//	// Add your key
////	KeyReg0_1 = HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
//
//	if ((KeyReg1_1 == KeyReg0_1) && (KeyReg1_1 == KeyReg2_1))
//	{
//		if (KeyReg2_1 != KeyReg3_1)
//		{
//			KeyReg3_1 = KeyReg2_1;
//			if (KeyReg3_1 == PRESSED_STATE1){
//				TimeOutForKeyPress_1 = 5000;
//				//subKeyProcess();
//				button1_flag = 1;
//			}
//		}
//		else
//		{
//			TimeOutForKeyPress_1--;
//			if (TimeOutForKeyPress_1 == 0){
//				TimeOutForKeyPress_1 = 5000;
//				if (KeyReg3_1 == PRESSED_STATE1){
//					//subKeyProcess();
//					button1_flag = 1;
//				}
//			}
//		}
//	}
//}
