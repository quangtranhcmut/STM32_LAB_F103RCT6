/*
 * usart2.h
 *
 *  Created on: Dec 1, 2024
 *      Author: Thảo Quảng
 */

#ifndef INC_USART2_H_
#define INC_USART2_H_

#include "main.h"
#include "string.h"
#include "timer.h"

#define MAX_BUFFER_SIZE 30

#define IDLE 0
#define CMDCHECK 1
#define SEND 2
#define WAIT 3

extern uint8_t temp;
extern uint8_t buffer[];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t cmd_state;
extern uint8_t num_char;
extern uint8_t temp_char[];
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;
extern uint32_t adc_value;
extern uint8_t adc_buffer[];

void command_parser_fsm();
void uart_communication_fsm();

#endif /* INC_USART2_H_ */
