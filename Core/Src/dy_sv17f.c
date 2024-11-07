/*
 * dy_sv17f.c
 *
 *  Created on: Nov 3, 2024
 *      Author: cchin
 */

#include <stdio.h>
#include "dy_sv17f.h"
static UART_HandleTypeDef *DYuart;

static uint8_t calculateChecksum(uint8_t *data, uint8_t length) {
    uint8_t sum = 0;
    for (uint8_t i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum & 0xFF;
}

static void send_command(uint8_t *cmd, uint8_t length) {
    uint8_t checksum = calculateChecksum(cmd + 1, length - 2);
    cmd[length - 1] = checksum;

    HAL_UART_Transmit(DYuart, cmd, length, HAL_MAX_DELAY);
}

void DY_Init(UART_HandleTypeDef *huart) {
    DYuart = huart;
}

uint8_t DY_GetPlayStatus(void) {
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

void DY_PlayTrack(uint16_t track) {
    // 0xAA + 0x07 + 0x02 + track_high + track_low
    uint8_t checksum = 0xAA + 0x07 + 0x02 + 0x00 + track;
	uint8_t cmd[] = {DY_START_BYTE, 0x07, 0x02, 0x00, track, checksum};
	send_command(cmd, sizeof(cmd));
}

uint8_t DY_GetCurrentDevice (void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x0A, 0x00, 0xB4};
	send_command(cmd, sizeof(cmd));

    uint8_t response[5];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);

    return response[3];
}

void DY_SelectDevice(uint8_t device) {
	uint8_t sum = 0xAA + 0x0B + 0x01 + device;
	uint8_t cmd[] = {DY_START_BYTE, 0x0B, 0x01, device, sum};
	send_command(cmd, sizeof(cmd));
}

uint16_t DY_GetTotalTracks(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x0C, 0x00, 0xB6};
	send_command(cmd, sizeof(cmd));

    uint8_t response[6];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);
    uint16_t totalTracks = (response[3] << 8) | response[4];

    return totalTracks ;
}

uint16_t DY_GetCurrentTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x0D, 0x00, 0xB7};
	send_command(cmd, sizeof(cmd));

    uint8_t response[6];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);
    uint16_t currentTracks = (response[3] << 8) | response[4];

    return currentTracks ;
}

void DY_PlayLastTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x0E, 0x00, 0xB8};
	send_command(cmd, sizeof(cmd));
}

void DY_PlayFirstTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x0F, 0x00, 0xB9};
	send_command(cmd, sizeof(cmd));
}

void DY_QuitCurrentPlay(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x10, 0x00, 0xBA};
	send_command(cmd, sizeof(cmd));
}

uint16_t DY_GetFirstTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x11, 0x00, 0xBB};
	send_command(cmd, sizeof(cmd));

    uint8_t response[6];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);
    uint16_t firstTrack = (response[3] << 8) | response[4];

    return firstTrack;
}

uint16_t DY_GetNumberTrack(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x12, 0x00, 0xBC};
	send_command(cmd, sizeof(cmd));

    uint8_t response[6];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);
    uint16_t numberTrack = (response[3] << 8) | response[4];

    return numberTrack;
}

void DY_SetVolume(uint8_t volume) {
	uint8_t sum = 0xAA + 0x13 + 0x01 + volume;
	uint8_t cmd[] = {DY_START_BYTE, 0x13, 0x01, volume, sum};
	send_command(cmd, sizeof(cmd));
}

void DY_VolumePlus(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x14, 0x00, 0xBE};
	send_command(cmd, sizeof(cmd));
}

void DY_VolumeMinus(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x15, 0x00, 0xBF};
	send_command(cmd, sizeof(cmd));
}

void DY_EQSetting(uint8_t EQMode) {
	uint8_t sum = 0xAA + 0x1A + 0x01 + EQMode;
	uint8_t cmd[] = {DY_START_BYTE, 0x1A, 0x01, EQMode, sum};
	send_command(cmd, sizeof(cmd));
}

TimeType DY_GetCurrentTrackLength(void) {
	TimeType time;
	uint8_t cmd[] = {DY_START_BYTE, 0x24, 0x00, 0xCE};
	send_command(cmd, sizeof(cmd));

    uint8_t response[7];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);

    time.hours = response[3];
    time.minutes = response[4];
    time.seconds = response[5];

    return time;
}

TimeType DY_UpdatePlayTime(void) {
	TimeType time;
	uint8_t cmd[] = {DY_START_BYTE, 0x24, 0x00, 0xCE};
	send_command(cmd, sizeof(cmd));

    uint8_t response[7];
    HAL_UART_Receive(DYuart, response, sizeof(response), HAL_MAX_DELAY);

    time.hours = response[3];
    time.minutes = response[4];
    time.seconds = response[5];

    return time;
}

void DY_ClosePlayTime(void) {
	uint8_t cmd[] = {DY_START_BYTE, 0x26, 0x00, 0xD0};
	send_command(cmd, sizeof(cmd));
}
