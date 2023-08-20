/*
 * LED.c
 *
 * Created: 8/20/2023 10:10:15 AM
 *  Author: Lenovo
 */ 

#include "LED.h"

void LED_init(){
	
	// Set All LEDs as Output
	DIO_setPinDirection(RED_PORT, RED_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(YELLOW_PORT, YELLOW_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(GREEN_PORT, GREEN_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(BLUE_PORT, BLUE_PIN, DIO_PIN_OUTPUT);
	
	// Turn OFF All LEDs
	DIO_WritePin(RED_PORT, RED_PIN, PIN_LOW);
	DIO_WritePin(YELLOW_PORT, YELLOW_PIN, PIN_LOW);
	DIO_WritePin(GREEN_PORT, GREEN_PIN, PIN_LOW);
	DIO_WritePin(BLUE_PORT, BLUE_PIN, PIN_LOW);
}

void RED_LED(uint8_t state){
	switch (state)
	{
		case ON:
		DIO_WritePin(RED_PORT, RED_PIN, PIN_HIGH);
		break;
		case OFF:
		DIO_WritePin(RED_PORT, RED_PIN, PIN_LOW);
		break;
	}
}

void YELLOW_LED(uint8_t state){
	switch (state)
	{
		case ON:
		ToggleBit(YELLOW_REGISTER, YELLOW_PIN);
		break;
		case OFF:
		DIO_WritePin(YELLOW_PORT, YELLOW_PIN, PIN_LOW);
		break;
	}
}

void GREEN_LED(uint8_t state){
	switch (state)
	{
		case ON:
		DIO_WritePin(GREEN_PORT, GREEN_PIN, PIN_HIGH);
		break;
		case OFF:
		DIO_WritePin(GREEN_PORT, GREEN_PIN, PIN_LOW);
		break;
	}
}

void BLUE_LED(uint8_t state){
	switch (state)
	{
		case ON:
		DIO_WritePin(BLUE_PORT, BLUE_PIN, PIN_HIGH);
		break;
		case OFF:
		DIO_WritePin(BLUE_PORT, BLUE_PIN, PIN_LOW);
		break;
	}
}

