/*
 * Traffic_control_lights.c
 *
 * Created: 8/20/2023 10:36:53 AM
 * Author : DELL
 */ 
#include "DIO.h"
#include "LCD.h"
#include "interrupts.h"
#include "LED.h"

EXTi_INTERRUPTconfiguration *external_interrupt_config;

int main(void)
{
	external_interrupt_config->EXTI_source = EX_INT1;
	external_interrupt_config->EXTI_trigger = FALLING_EDGE;
	external_interrupt_config->IRQ_en = GLOBAL_INT1_EN;
	external_interrupt_config->Flag_clear = GLOBAL_INT1_FLAG;
	
	LCD_init();
	LCD_Clear();
	
		DIO_setPinDirection(DIO_PORTA, DIO_PIN4, PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTA, DIO_PIN5, PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTA, DIO_PIN6, PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTB, DIO_PIN7, PIN_OUTPUT);
		
		EXTI_interruptconfig(external_interrupt_config);

    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(INT1_vect)
{
	LCD_Clear();
	LED_init();
	_delay_ms(150);
	const uint8_t *str = "aaaaaa";
	LCD_WriteString(str);
	
	RED_LED(ON);
	_delay_ms(150);
	BLUE_LED(ON);
	_delay_ms(150);
	PORTA ^= (1<<4);
	_delay_ms(150);
	PORTA ^= (1<<5);
	_delay_ms(150);
	SetBit(GIFR, external_interrupt_config->Flag_clear);
}