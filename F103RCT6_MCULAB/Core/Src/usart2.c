/*
 * usart2.c
 *
 *  Created on: Dec 1, 2024
 *      Author: Thảo Quảng
 */

#include "usart2.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t current_index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t cmd_flag = 0;
uint8_t cmd_end_flag = 0;

uint8_t uart_state = IDLE;
uint8_t cmd_state = CMD_INIT;
uint8_t cmd_rts_flag = 0;
uint8_t cmd_ok_flag = 0;
uint32_t adc_value = 0;
uint8_t adc_buffer[10];
uint8_t start_index = 0;

void command_parser_fsm(){
	switch (cmd_state) {
		case CMD_INIT: {
			if (cmd_flag == 1) {
				cmd_flag = 0;
				cmd_state = CMD_FIND;
			}
			break;
		}
		case CMD_FIND: {
			start_index = current_index_buffer;
			if (buffer[start_index] == '!'
				&& buffer[start_index + 1] == 'R'
				&& buffer[start_index + 2] == 'T'
				&& buffer[start_index + 3] == 'S'
				&& buffer[start_index + 4] == '#') {
				cmd_rts_flag = 1;
				cmd_state = CMD_INIT;
				break;
			}
			if (buffer[start_index] == '!'
				&& buffer[start_index + 1] == 'O'
				&& buffer[start_index + 2] == 'K'
				&& buffer[start_index + 3] == '#') {
				cmd_ok_flag = 1;
				cmd_state = CMD_INIT;
				break;
			}
			break;
		}
		default: {
			break;
		}
	}
}

void uart_communication_fsm(){
	switch (uart_state) {
		case IDLE: {
			if (cmd_end_flag == 1) {
				cmd_end_flag = 0;
				uart_state = CMDCHECK;
			}
			setTimer(1, 1000);
			break;
		}
		case CMDCHECK: {
			if (cmd_rts_flag == 1) {
				uart_state = SEND;
				cmd_rts_flag = 0;
				break;
			}
			if (cmd_ok_flag == 1){
				uart_state = IDLE;
				cmd_ok_flag = 0;
				break;
			}
			if (timer_flag[1] == 1) {
				uart_state = IDLE;
			}
			break;
		}
		case SEND: {
			HAL_ADC_Start(&hadc1);
			if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
				adc_value = HAL_ADC_GetValue(&hadc1);
				sprintf((char *)adc_buffer, "!ADC=%lu#", adc_value);
				HAL_UART_Transmit(&huart2, adc_buffer, 10, 10);
				setTimer(0, 5000);
	        	uart_state = WAIT;
			}
			HAL_ADC_Stop(&hadc1);
			break;
		}
		case WAIT: {
			if(timer_flag[0] == 1) {
				uart_state = IDLE;
				break;
			}
			if (cmd_ok_flag == 1) {
				cmd_ok_flag = 0;
				uart_state = IDLE;
				break;
			}
			break;
		}
		default: {
			break;
		}
	}
}
