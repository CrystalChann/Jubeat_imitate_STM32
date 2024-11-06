/*
 * uart.c
 *
 *  Created on: Nov 3, 2024
 *      Author: cchin
 */

#include "uart.h"

static UART_HandleTypeDef *uart_handle;

void UART_Init(UART_HandleTypeDef *huart) {
    uart_handle = huart;
}

void UART_Transmit(uint8_t *data, uint16_t size) {
    HAL_UART_Transmit(uart_handle, data, size, 100);
}

uint8_t UART_Receive(uint8_t *data, uint16_t size, uint32_t timeout) {
    return HAL_UART_Receive(uart_handle, data, size, timeout);
}
