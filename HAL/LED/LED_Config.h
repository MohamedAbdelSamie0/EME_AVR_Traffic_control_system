/*
 * LED_Config.h
 *
 * Created: 8/20/2023 10:26:22 AM
 *  Author: Lenovo
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "Atmega32_Registers.h"
#include "DIO.h"

//====================================================================
//						PORT Configuration
//====================================================================

#define RED_PORT			DIO_PORTB
#define YELLOW_PORT			DIO_PORTA
#define GREEN_PORT			DIO_PORTA
#define BLUE_PORT			DIO_PORTA

#define YELLOW_REGISTER		PORTA

//====================================================================
//						PIN Configuration
//====================================================================

#define RED_PIN				DIO_PIN7
#define YELLOW_PIN			DIO_PIN6
#define GREEN_PIN			DIO_PIN4
#define BLUE_PIN			DIO_PIN5

//====================================================================
//						STATE Configuration
//====================================================================

#define ON					1
#define OFF					0


#endif /* LED_CONFIG_H_ */