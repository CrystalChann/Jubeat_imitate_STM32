/*
 * uart.h
 *
 *  Created on: Nov 3, 2024
 *      Author: cchin
 */

#ifndef UART_H
#define UART_H

#include "stm32f1xx_hal.h"

void UART_Init(UART_HandleTypeDef *huart);
void UART_Transmit(uint8_t *data, uint16_t size);
uint8_t UART_Receive(uint8_t *data, uint16_t size, uint32_t timeout);

#endif

