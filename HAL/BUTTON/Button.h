/*
 * Button.h
 *
 * Created: 8/20/2023 10:13:17 AM
 *  Author: Lenovo
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "Button_Config.h"

#ifndef F_CPU
	#define  F_CPU			16000000UL
#endif

#include <util/delay.h>

enum states{
	NORMAL = 2,
	RED
};

void PedestrianButton_init();


#endif /* BUTTON_H_ */