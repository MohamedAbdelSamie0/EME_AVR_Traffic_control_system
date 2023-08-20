/*
 * APP.h
 *
 * Created: 8/20/2023 12:59:39 PM
 *  Author: DELL
 */ 

#include "Button.h"
#include "LED.h"
#include "LCD.h"
#include "DIO.h"

#define GREEN		0
#define YELLOW		1
#define BLUE		2

#define FIVE_SEC	5000

#define green_state	10
#define yellow_state 11
#define red_state	12


void RED_STATE();

void delay_5secs(uint32_t delay);
void Traffic_state(uint8_t *tr_state);
void YellowBlink();