/*
 * second_song.c
 *
 *  Created on: Nov 26, 2024
 *      Author: cchin
 */


#include "blank_space.h"
#include "dy_sv17f.h"
#include "lcd.h"

void an_apple_LCD(void) {
			LCD_Clear(0, 0, 240, 320, WHITE);
		  LCD_DrawString(60,50,"An Apple");
		  LCD_DrawString(100,80,"-- Mayday ");
		  LCD_DrawString(20,110,"Difficulty: Normal");
		  LCD_DrawString(20,130,"Score: 0000");
		  LCD_DrawString(100,170,"Playing");
		  LCD_DrawString(200,200," ");
}

void an_apple_musicMap(void) {

}