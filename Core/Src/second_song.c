/*
 * second_song.c
 *
 *  Created on: Nov 26, 2024
 *      Author: cchin
 */


#include "blank_space.h"
#include "dy_sv17f.h"
#include "lcd.h"

void second_song_LCD(void) {
			LCD_Clear(0, 0, 240, 320, WHITE);
		  LCD_DrawString(60,50,"Second Song");
		  LCD_DrawString(100,80,"--Author ");
		  LCD_DrawString(20,110,"Difficulty: Easy");
		  LCD_DrawString(20,130,"Score: 0000");
		  LCD_DrawString(100,170,"Playing");
		  LCD_DrawString(200,200," ");

}

void second_song_musicMap(void) {
	DY_PlayTrack(0x02);
}
