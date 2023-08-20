/*
 * Traffic Control.c
 *
 * Created: 8/20/2023 9:44:44 AM
 * Author : Lenovo
 */ 

#include "APP.h"

uint8_t state = green_state;

int main(void)
{
	
	LED_init();
	LCD_Init();
	LCD_Clear();
	state = green_state;

	PedestrianButton_init();	
	
	Traffic_state(&state);
}

