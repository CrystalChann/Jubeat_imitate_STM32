/*
 * dy_sv17f.c
 *
 *  Created on: Nov 6, 2024
 *      Author: cchin
 */

#include "dy_sv17f.h"
static UART_HandleTypeDef *DYuart;

static uint8_t calculateChecksum(uint8_t *data, uint8_t length) {
    uint8_t sum = 0;
    for (uint8_t i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

static void sendCommand(uint8_t *cmd, uint8_t length) {
    uint8_t checksum = calculateChecksum(cmd + 1, length - 2);
    cmd[length - 1] = checksum;

    HAL_UART_Transmit(DYuart, cmd, length, HAL_MAX_DELAY);
}

void DY_Init(UART_HandleTypeDef *huart) {
    DYuart = huart;
}

void DY_GetPlayStatus(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x01, 0x00, 0xAB};
	send_command(cmd, sizeof(cmd));

    uint8_t response[5];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);

    return response[3];
}

void DY_Play(void) {
    uint8_t cmd[] = {DY_START_BYTE, 0x02, 0x00, 0xAC};
    send_command(cmd, sizeof(cmd));
}

void DY_Pause(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x03, 0x00, 0xAD};
	send_command(cmd, sizeof(cmd));
}

void DY_Stop(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x04, 0x00, 0xAE};
	send_command(cmd, sizeof(cmd));
}

void DY_PrevTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x05, 0x00, 0xAF};
	send_command(cmd, sizeof(cmd));
}

void DY_NextTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x06, 0x00, 0xB0};
	send_command(cmd, sizeof(cmd));
}
