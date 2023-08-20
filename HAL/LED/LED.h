/*
 * LED.h
 *
 * Created: 8/20/2023 10:10:28 AM
 *  Author: Lenovo
 */ 


#ifndef LED_H_
#define LED_H_

#include "LED_Config.h"
#include "BitMath.h"

void LED_init();
void RED_LED(uint8_t state);
void YELLOW_LED(uint8_t state);
void GREEN_LED(uint8_t state);
void BLUE_LED(uint8_t state);

#endif /* LED_H_ */