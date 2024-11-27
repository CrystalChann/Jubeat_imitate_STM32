/*
 * menu.c
 *
 *  Created on: Nov 25, 2024
 *      Author: cchin
 */

#include "menu.h"
#include "dy_sv17f.h"

void printMenu(int track) {
	  LCD_DrawString(10,25,"Welcome back to ");
	  LCD_DrawString(90,50,"Jubeat!");
	  LCD_DrawString(10,90,"1.Blank Space - Taylor Swift");
	  LCD_DrawString(10,120,"2.An Apple - Mayday");
	  LCD_DrawString(10,150,"3.Bedroom Star - TNT");

	  switch (track) {
	  	  case (0):
				LCD_DrawString(15, 300, "< Default : Blank Space  >");
			  	break;
	  	  case (1):
				LCD_DrawString(15, 300, "< Selected: Blank Space  >");
				break;
	  	  case (2):
	  			LCD_DrawString(15, 300, "< Selected: An Apple     >");
	  	  	  	break;
	  	  case (3):
				LCD_DrawString(15, 300, "< Selected: Bedroom Star >");
	  }
}


void resetAll(void) {

}
