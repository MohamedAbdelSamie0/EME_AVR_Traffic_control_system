/*
 * APP.c
 *
 * Created: 8/20/2023 12:59:28 PM
 *  Author: DELL
 */ 


#include "APP.h"

uint8_t g_BREAK_DELAY = 1;
uint8_t traffic_light_state = green_state;

void delay_5secs(uint32_t delay)
{
	   for (uint16_t i = 0; i < delay; i++) {
		   // Each iteration of this loop introduces a delay of about 1ms using _delay_us
		   _delay_us(1000);  // Delay for 1000 microseconds (1ms)
		   if(!g_BREAK_DELAY)
				break;
	   }
}

/*Function to blink yellow led	*/
void YellowBlink(){
	int count = 5;
	while(--count){
		YELLOW_LED(ON);
		delay_5secs(1000);
	}
	YELLOW_LED(OFF);
}


void Traffic_state()
{
	while(1)
	{
		switch(traffic_light_state)
		{
			case green_state:

			g_BREAK_DELAY = 1;
			GREEN_LED(ON);
			delay_5secs(FIVE_SEC);
			GREEN_LED(OFF);
			BLUE_LED(OFF);
			if(g_BREAK_DELAY)
				traffic_light_state = yellow_state;
			else
				traffic_light_state = green_state;
			break;
		
			case yellow_state:
			g_BREAK_DELAY = 1;
			YellowBlink();
			BLUE_LED(OFF);
			if(traffic_light_state == yellow_state)
				traffic_light_state = red_state;
			else
				traffic_light_state = green_state;
			break;
		
			case red_state:
			g_BREAK_DELAY = 1;
		
			RED_LED(ON);
			BLUE_LED(ON);
			delay_5secs(FIVE_SEC);
			RED_LED(OFF);
			BLUE_LED(OFF);
			traffic_light_state = green_state;
			break;
		}
	}
		
}