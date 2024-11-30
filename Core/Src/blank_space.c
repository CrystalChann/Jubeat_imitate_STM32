/*
 * blank_space.c
 *
 *  Created on: Nov 25, 2024
 *      Author: cchin
 */

#include "blank_space.h"
#include "dy_sv17f.h"
#include "lcd.h"
#include "led_blink.h"

uint32_t lastToggleTime_blank = 0;
uint8_t currentState_blank = 0;
int cycleFinished_blank = 0;

void blank_space_LCD(void) {
		  LCD_Clear(0, 0, 240, 320, WHITE);
		  LCD_DrawString(60,50,"Blank Space");
		  LCD_DrawString(100,80,"--Taylor Swift ");
		  LCD_DrawString(20,110,"Difficulty: Easy");
		  LCD_DrawString(100,170,"Playing");
		  LCD_DrawString(200,200," ");

}

void blank_space_musicMap(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

    uint32_t currentTime = HAL_GetTick();
    uint32_t interval;

    switch (currentState_blank % 2) {
        case 0:
            interval = 250; // 250ms
            break;
        case 1:
            interval = 300; // 300ms
            break;
        default:
            interval = 300;
            break;
    }

    // Change states based on the current time and interval
    if (currentTime - lastToggleTime_blank >= interval && cycleFinished_blank < 32) {
        lastToggleTime_blank = currentTime;

        switch (currentState_blank) {
            case 0:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET); // key 3 red off
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET); // key 1 green on
                break;
            case 1:
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); // key 1 green off
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET); // key1 red on
                break;
            case 2:
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET); // key1 red off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); //key 2 green on
                break;
            case 3:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET); // key 2 green off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); //key 2 red on
                break;
            case 4:
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET); //key 2 red off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); //key 4 green on
                break;
            case 5:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET); // key 4 green off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET); //key 4 red on
        		break;
            case 6:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET); // key 4 red off
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET); // key 1 green on
            	break;
            case 7:
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); // key 1 green off
            	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET); // key 1 red on
            	break;
            case 8:
        		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET); // key 1 red off
        		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); //key 3 green on
        		break;
            case 9:
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET); // key 3 green off
            	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET); // key 3 red on
            	cycleFinished_blank += 1;
            	break;

            default:
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
                break;
        }

        currentState_blank = (currentState_blank + 1) % 10;
    }
}
