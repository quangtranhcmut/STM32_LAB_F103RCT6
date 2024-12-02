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
uint8_t buffer_flag = 0;

uint8_t cmd_state = IDLE;

uint8_t num_char = 0;
uint8_t temp_char[] = "";
uint32_t adc_value = 0;
uint8_t adc_buffer[30];

void command_parser_fsm(){
	switch (cmd_state) {
		case IDLE: {
			if (buffer[index_buffer] == '!') {
				cmd_state = CMDCHECK;
				break;
			}
			break;
		}
		case CMDCHECK: {
			if (buffer[index_buffer] != '#') {
				temp_char[num_char] = buffer[index_buffer];
				num_char++;
			}
			if (buffer[index_buffer] == '#') {
				if (strcmp((char *)temp_char, "RTS") == 0) {
					cmd_state = SEND;
					memset(temp_char, '\0', sizeof(temp_char));
					num_char = 0;
					break;
				}
				if (strcmp((char *)temp_char, "RTS") != 0) {
					cmd_state = IDLE;
					memset(temp_char, '\0', sizeof(temp_char));
					num_char = 0;
					break;
				}
			}
			if (num_char > 10) {
				cmd_state = IDLE;
				memset(temp_char, '\0', sizeof(temp_char));
				num_char = 0;
				break;
			}
			break;
		}
		case SEND: {
		    HAL_ADC_Start(&hadc1);
		    if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
		        adc_value = HAL_ADC_GetValue(&hadc1);
		    }
		    HAL_ADC_Stop(&hadc1);
//		    snprintf((uint8_t *)adc_buffer, buffer_size, "ADC=%lu", adc_value);
			HAL_UART_Transmit(&huart2, (uint8_t *)"ABC", 3, 50);
			memset(adc_buffer, '\0', sizeof(adc_buffer));
			break;
		}
		default: {
			break;
		}
	}
}
void uart_communication_fsm(){

}
