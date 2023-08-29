/*
 * LCD_Cfg.h
 *
 * Created: 18-Aug-23 10:22:36 AM
 *  Author: Mohamed Abdelsamie
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO.h"

#define LCD_MODE	4

/* LCD Commands */
#define FUNCTION_SET						0x28
#define CLEAR_DISPLAY						0x01
#define DISPLAY_ON_CURSOR_BLINKING			0x0F

#define LCD_GO_TO_HOME                      0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE       0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE        0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1  0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2  0x32
#define LCD_CURSOR_OFF                      0x0C
#define LCD_CURSOR_ON                       0x0E
#define LCD_BEGIN_AT_FIRST_ROW			 	0x80
#define LCD_BEGIN_AT_SECOND_ROW				0xc0
#define LCD_BEGIN_AT_THIRD_ROW				0x94
#define LCD_BEGIN_AT_FOURTH_ROW				0xE0
#define LCD_SET_CURSOR_LOCATION             0x80

#define LCD_4BIT_CMD_PORT	 DIO_PORTA  
#define LCD_4BIT_DATA_PORT	 DIO_PORTB  

#define  LCD_RS_PIN		DIO_PIN3
#define  LCD_RW_PIN     DIO_PIN1
#define  LCD_EN_PIN		DIO_PIN2
    
#define LCD_D4		DIO_PIN0
#define LCD_D5		DIO_PIN1
#define LCD_D6		DIO_PIN2
#define LCD_D7      DIO_PIN4
    


#endif /* LCD_CFG_H_ */