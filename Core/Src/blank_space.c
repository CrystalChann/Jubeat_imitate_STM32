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

void blank_space_LCD(void) {
		  LCD_Clear(0, 0, 240, 320, WHITE);
		  LCD_DrawString(60,50,"Blank Space");
		  LCD_DrawString(100,80,"--Taylor Swift ");
		  LCD_DrawString(20,110,"Difficulty: Easy");
		  LCD_DrawString(20,130,"Score: 0000");
		  LCD_DrawString(100,170,"Playing");
		  LCD_DrawString(200,200," ");

}

void blank_space_musicMap(void) {
	Blink_LED1(0);
	Blink_LED2(0);
	Blink_LED3(0);
	Blink_LED4(0);
}
