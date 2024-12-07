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
#include <stdio.h>

#define MAX_BUFFER_SIZE 30

#define IDLE 0
#define CMDCHECK 1
#define SEND 2
#define WAIT 3

#define CMD_INIT 11
#define CMD_FIND 12

extern uint8_t temp;
extern uint8_t buffer[];
extern uint8_t index_buffer;
extern uint8_t current_index_buffer;
extern uint8_t buffer_flag;
extern uint8_t cmd_flag;
extern uint8_t cmd_end_flag;

extern uint8_t uart_state;
extern uint8_t cmd_state;
extern uint8_t cmd_rts_flag;
extern uint8_t cmd_ok_flag;
extern uint32_t adc_value;
extern uint8_t adc_buffer[];
extern uint8_t start_index;
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

void command_parser_fsm();
void uart_communication_fsm();

#endif /* INC_USART2_H_ */
