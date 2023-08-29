/*
 * Traffic Control.c
 *
 * Created: 8/20/2023 9:44:44 AM
 * Author : Lenovo
 */ 

#include "APP.h"

int main(void)
{
	
	LED_init();
	LCD_Init();
	LCD_Clear();
	LCD_Goto(2, 5);
	LCD_WriteString((uint8_t*)"CARS        ");

	PedestrianButton_init();	
	
	Traffic_state();
}

