/*
 * dy_sv17f.h
 *
 *  Created on: Nov 3, 2024
 *      Author: cchin
 */

#ifndef INC_DY_SV17F_H_
#define INC_DY_SV17F_H_

#include "uart.h"

// Command definitions
#define DY_START_BYTE    0xAA

// Play status
#define DY_STATUS_STOP     0x00
#define DY_STATUS_PLAYING  0x01
#define DY_STATUS_PAUSE    0x02

#define DY_DEVICE_USB    0x00
#define DY_DEVICE_SD     0x01
#define DY_DEVICE_FLASH  0x02

typedef struct {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
} TimeType;

// Function
void DY_Init(UART_HandleTypeDef *huart);
uint8_t DY_GetPlayStatus(void); //01
void DY_Play(void); //02
void DY_Pause(void); //03
void DY_Stop(void); //04
void DY_PrevTrack(void); //05
void DY_NextTrack(void); //06
void DY_PlayTrack(uint8_t track); //07
// play specific song with path 08
uint8_t DY_GetCurrentDevice (void); //0A
void DY_SelectDevice(uint8_t device); //0B
uint16_t DY_GetTotalTracks(void); //0C
uint16_t DY_GetCurrentTrack(void); //0D
void DY_PlayLastTrack(void); //0E
void DY_PlayFirstTrack(void); //0F
void DY_QuitCurrentPlay(void); //10
uint16_t DY_GetFirstTrack(void); //11
uint16_t DY_GetNumberTrack(void); //12
void DY_SetVolume(uint8_t volume); //13
void DY_VolumePlus(void); //14
void DY_VolumeMinus(void); //15
void DY_EQSetting(uint8_t EQMode); //1A
TimeType DY_GetCurrentTrackLength(void); //24
TimeType DY_UpdatePlayTime(void); //25
void DY_ClosePlayTime(void); //26

//tester
void DY_PlayBlankSpace(void);
void DY_volumeTo14(void);
void DY_PlayAnApple(void);



#endif /* INC_DY_SV17F_H_ */
