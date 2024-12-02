///*
// * matrix.c
// *
// *  Created on: Sep 30, 2024
// *      Author: Thảo Quảng
// */
//
//
//#include "matrix.h"
//
//void resetAllColumns(){
//	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 0);
//	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 0);
//	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 0);
//	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 0);
//	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 0);
//	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 0);
//	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 0);
//	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 0);
//}
//
//const int MAX_LED_MATRIX = 8;
//int index_led_matrix = 0;
//uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x7E, 0x66, 0x7E, 0x7E, 0x66, 0x66};
//void updateLEDMatrix(int index) {
//	resetAllColumns();
//    switch (index) {
//        case 0: {
//        	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, 1);
//            break;
//        }
//        case 1: {
//			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, 1);
//			break;
//		}
//        case 2: {
//			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, 1);
//			break;
//		}
//        case 3: {
//			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, 1);
//			break;
//		}
//        case 4: {
//			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, 1);
//			break;
//		}
//        case 5: {
//			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, 1);
//			break;
//		}
//        case 6: {
//			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, 1);
//			break;
//		}
//        case 7: {
//			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, 1);
//			break;
//		}
//        default: {
//            break;
//        }
//    }
//
//    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, matrix_buffer[index] & 0x01);
//    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, matrix_buffer[index] & 0x02);
//    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, matrix_buffer[index] & 0x04);
//    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, matrix_buffer[index] & 0x08);
//    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, matrix_buffer[index] & 0x10);
//    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, matrix_buffer[index] & 0x20);
//    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, matrix_buffer[index] & 0x40);
//    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, matrix_buffer[index] & 0x80);
//}
//
//void shiftLeft() {
//    uint8_t temp0 = (matrix_buffer[0] & 0x80) >> 7;
//    uint8_t temp1 = (matrix_buffer[1] & 0x80) >> 7;
//    uint8_t temp2 = (matrix_buffer[2] & 0x80) >> 7;
//    uint8_t temp3 = (matrix_buffer[3] & 0x80) >> 7;
//    uint8_t temp4 = (matrix_buffer[4] & 0x80) >> 7;
//    uint8_t temp5 = (matrix_buffer[5] & 0x80) >> 7;
//    uint8_t temp6 = (matrix_buffer[6] & 0x80) >> 7;
//    uint8_t temp7 = (matrix_buffer[7] & 0x80) >> 7;
//
//    matrix_buffer[0] = (matrix_buffer[0] << 1) | temp0;
//    matrix_buffer[1] = (matrix_buffer[1] << 1) | temp1;
//    matrix_buffer[2] = (matrix_buffer[2] << 1) | temp2;
//    matrix_buffer[3] = (matrix_buffer[3] << 1) | temp3;
//    matrix_buffer[4] = (matrix_buffer[4] << 1) | temp4;
//    matrix_buffer[5] = (matrix_buffer[5] << 1) | temp5;
//    matrix_buffer[6] = (matrix_buffer[6] << 1) | temp6;
//    matrix_buffer[7] = (matrix_buffer[7] << 1) | temp7;
//}
