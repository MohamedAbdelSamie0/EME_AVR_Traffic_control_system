/*
 * Button.c
 *
 * Created: 8/20/2023 10:13:36 AM
 *  Author: Lenovo
 */ 

#include "Button.h"
#include "interrupts.h"
#include "LED.h"
#include "APP.h"
#include <avr/interrupt.h>

EXTi_INTERRUPTconfiguration *EXTI_Config;
extern uint8_t g_BREAK_DELAY;
extern uint8_t state;

void PedestrianButton_init(){
	DIO_setPinDirection(PEDESTRIAN_PORT, PEDESTRIAN_PIN, DIO_PIN_INPUT);
	
	EXTI_Config->EXTI_source = EX_INT1;
	EXTI_Config->EXTI_trigger = ANY_LOGIC_CHANGE;
	EXTI_Config->IRQ_en = GLOBAL_INT1_EN;
	EXTI_Config->Flag_clear = GLOBAL_INT1_FLAG;
	
	EXTI_interruptconfig(EXTI_Config);
}

ISR(INT1_vect){
	
	switch(state)
	{
		default:
		
		state = green_state;
		GREEN_LED(OFF);
		YellowBlink();
		LCD_Clear();
		LCD_WriteString("	PEDESTRIAN");
		BLUE_LED(ON);
		RED_LED(ON);
		_delay_ms(5000);
		BLUE_LED(OFF);
		RED_LED(OFF);
		break;
		
		case red_state:
		
		state = green_state;
		BLUE_LED(ON);
		_delay_ms(5000);
		break;
	}
	
		g_BREAK_DELAY = 0;
		
	SetBit(GIFR, EXTI_Config->Flag_clear);
	
}

