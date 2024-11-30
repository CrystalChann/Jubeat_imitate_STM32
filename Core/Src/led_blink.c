/*
 * led_blink.c
 *
 *  Created on: Nov 27, 2024
 *      Author: cchin
 */

#include "led_blink.h"
#include <stdint.h>
#include "main.h"

uint32_t lastToggleTime1 = 0;
uint8_t currentState1 = 0;

uint32_t lastToggleTime2 = 0;
uint8_t currentState2 = 0;

uint32_t lastToggleTime3 = 0;
uint8_t currentState3 = 0;

uint32_t lastToggleTime4 = 0;
uint8_t currentState4 = 0;

void Blink_LED1(int cycleFinished) {
    uint32_t currentTime = HAL_GetTick(); // Get the current time


    // Change states based on the current time
    if (currentTime - lastToggleTime1 >= 250 && cycleFinished == 0) { // Change every 250 ms
    	lastToggleTime1 = currentTime; // Update the last toggle time

        switch (currentState1) {
            case 0: // Off
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
                break;
            case 1: // Green
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
                break;
            case 2: // Yellow, stay green, enable red
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
                break;
            case 3: // Red, disable green
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                break;
            case 4: // off again
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
                cycleFinished = 1;
                break;
            default:
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
                break;
        }

        // Move to the next state
        currentState1 = (currentState1 + 1) % 5; // Cycle from 0 to 4 (0: off, 1: blue, 2: green, 3: red, 4: off)

    }
}

void Blink_LED2(int cycleFinished) {
    uint32_t currentTime = HAL_GetTick(); // Get the current time


    // Change states based on the current time
    if (currentTime - lastToggleTime2 >= 250 && cycleFinished == 0) { // Change every 250 ms
    	lastToggleTime2 = currentTime; // Update the last toggle time

        switch (currentState2) {
            case 0: // Off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
                break;
            case 1: // Green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
                break;
            case 2: // Yellow, stay green, enable red
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
                break;
            case 3: // Red, disable green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
                break;
            case 4: // off again
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
                cycleFinished = 1;
                break;
            default:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
                break;
        }

        // Move to the next state
        currentState2 = (currentState2 + 1) % 5; // Cycle from 0 to 4 (0: off, 1: blue, 2: green, 3: red, 4: off)
    }
}

void Blink_LED3(int cycleFinished) {
    uint32_t currentTime = HAL_GetTick(); // Get the current time


    // Change states based on the current time
    if (currentTime - lastToggleTime3 >= 250 && cycleFinished == 0) { // Change every 250 ms
    	lastToggleTime3 = currentTime; // Update the last toggle time

        switch (currentState3) {
            case 0: // Off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
                break;
            case 1: // Green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
                break;
            case 2: // Yellow, stay green, enable red
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
                break;
            case 3: // Red, disable green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
                break;
            case 4: // off again
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
                cycleFinished = 1;
                break;
            default:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
                break;
        }

        // Move to the next state
        currentState3 = (currentState3 + 1) % 5; // Cycle from 0 to 4 (0: off, 1: blue, 2: green, 3: red, 4: off)
    }
}

void Blink_LED4(int cycleFinished) {
    uint32_t currentTime = HAL_GetTick(); // Get the current time


    // Change states based on the current time
    if (currentTime - lastToggleTime4 >= 250 && cycleFinished == 0) { // Change every 250 ms
    	lastToggleTime4 = currentTime; // Update the last toggle time

        switch (currentState4) {
            case 0: // Off
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
                break;
            case 1: // Green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
                break;
            case 2: // Yellow, stay green, enable red
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
                break;
            case 3: // Red, disable green
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
                break;
            case 4: // off again
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
                cycleFinished = 1;
                break;
            default:
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
                break;
        	}

        // Move to the next state
        currentState4 = (currentState4 + 1) % 5; // Cycle from 0 to 4 (0: off, 1: blue, 2: green, 3: red, 4: off)
    }
}
