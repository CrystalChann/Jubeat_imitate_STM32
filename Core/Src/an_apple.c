/*
 * second_song.c
 *
 *  Created on: Nov 26, 2024
 *      Author: cchin
 */


#include "blank_space.h"
#include "dy_sv17f.h"
#include "lcd.h"

uint32_t lastToggleTime_apple = 0;
uint8_t currentState_apple = 0;
int cycleFinished_apple = 0;

void an_apple_LCD(void) {
		  LCD_Clear(0, 0, 240, 320, WHITE);
		  LCD_DrawString(60,50,"An Apple");
		  LCD_DrawString(100,80,"-- Mayday ");
		  LCD_DrawString(20,110,"Difficulty: Normal");
		  LCD_DrawString(100,170,"Playing");
		  LCD_DrawString(200,200," ");
}

void an_apple_musicMap(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

    uint32_t currentTime = HAL_GetTick();
    uint32_t interval;

    switch (currentState_apple % 2) {
        case 0:
            interval = 100; // 100ms
            break;
        case 1:
            interval = 172; // 172ms
            break;
        default:
            interval = 172;
            break;
    }

    // Change states based on the current time and interval
    if (currentTime - lastToggleTime_apple >= interval && cycleFinished_apple < 38) {
        lastToggleTime_apple = currentTime;

        switch (currentState_apple) {
            case 0:
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET); // key 1 red off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); // key 3 green on
                break;
            case 1:
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // key 3 green off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); // key3 red on
                break;
            case 2:
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); // key3 red off
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET); //key 1 green on
                break;
            case 3:
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); // key 1 green off
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET); //key 1 red on
                break;
            case 4:
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET); //key 1 red off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); //key 4 green on
                break;
            case 5:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET); // key 4 green off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET); //key 4 red on
        		break;
            case 6:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET); // key 4 red off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // key 2 green on
            	break;
            case 7:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); // key 2 green off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); // key 2 red on
            	break;
            case 8:
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET); // key 2 red off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); //key 3 green on
        		break;
            case 9:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // key 3 green off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); // key 3 red on
            	break;
            case 10:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); // key 3 red off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // key 2 green on
            	break;
            case 11:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); //key 2 green off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // key 2 red on
            	break;
            case 12:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); // key 2 red off
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET); // key 1 green on
            	break;
            case 13:
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); // key 1 green off
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET); // key 1 red on
            	cycleFinished_apple += 1;
            default:
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
                break;
        }

        currentState_apple = (currentState_apple + 1) % 14;
    }
}
