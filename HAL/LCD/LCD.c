/*
 * LCD.c
 *
 * Created: 8/20/2023 11:20:18 AM
 *  Author: DELL
 */ 
#include "LCD.h"
#define  F_CPU			16000000UL
#include <util/delay.h>

void LCD_Init(void)
{
    
    DIO_setPinDirection(LCD_4BIT_CMD_PORT ,LCD_RS_PIN ,DIO_PIN_OUTPUT);
    //DIO_setPinDirection(LCD_4BIT_CMD_PORT ,LCD_RW_PIN ,DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,DIO_PIN_OUTPUT);
    
    DIO_setPinDirection(LCD_4BIT_DATA_PORT ,LCD_D4 ,DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_4BIT_DATA_PORT ,LCD_D5 ,DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_4BIT_DATA_PORT ,LCD_D6 ,DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_4BIT_DATA_PORT ,LCD_D7 ,DIO_PIN_OUTPUT);
    
   _delay_ms(1);


    LCD_WriteCommand (FUNCTION_SET);
    _delay_ms(1);
    LCD_WriteCommand (CLEAR_DISPLAY); 
    _delay_ms(1);
    LCD_WriteCommand (DISPLAY_ON_CURSOR_BLINKING); 
    _delay_ms(1);

    
    
}

void LCD_WriteCommand(uint8_t cmd)
{
    /*
    RS (Register Select)
    RS = 0 -> Command Register is selected
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RS_PIN ,PIN_LOW);
    _delay_ms(1);

    /*
    For 4-bit interface data, only four bus lines (DB4 to DB7) are used for transfer. Bus lines DB0 to DB3
    are disabled. The data transfer between the HD44780U and the MPU is completed after the 4-bit data
    has been transferred twice. As for the order of data transfer, the four high order bits (for 8-bit operation,
    DB4 to DB7) are transferred before the four low order bits (for 8-bit operation, DB0 to DB3).
    */
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D4 , GetBit(cmd,4));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D5 , GetBit(cmd,5));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D6 , GetBit(cmd,6));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D7 , GetBit(cmd,7));
    _delay_ms(1);
    
    
    /*
    Falling Edge to process the data
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_HIGH);
    _delay_ms(1);
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_LOW);      
    _delay_ms(1);


    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D4 , GetBit(cmd,0));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D5 , GetBit(cmd,1));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D6 , GetBit(cmd,2));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D7 , GetBit(cmd,3));
    _delay_ms(1);
    
    /*
    Falling Edge to process the data
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_HIGH);     
    _delay_ms(1);
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_LOW);
    
    _delay_ms(5); // LCD store delay
}

void LCD_WriteChar(uint8_t chr)
{  
    /*
    RS (Register Select)
    RS = 1 -> Data Register is selected
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RS_PIN ,PIN_HIGH);
    _delay_ms(1);

    
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D4 , GetBit(chr,4));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D5 , GetBit(chr,5));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D6 , GetBit(chr,6));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D7 , GetBit(chr,7));
    _delay_ms(1);
    
    
    /*
    Falling Edge to process the data
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_HIGH);
    _delay_ms(1);
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_LOW);     
    _delay_ms(1);


    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D4 , GetBit(chr,0));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D5 , GetBit(chr,1));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D6 , GetBit(chr,2));
    DIO_WritePin (LCD_4BIT_DATA_PORT, LCD_D7 , GetBit(chr,3));
    _delay_ms(1);
    
    /*
    Falling Edge to process the data
    */
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_HIGH);     //Enable=1
    _delay_ms(1);
    DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_EN_PIN ,PIN_LOW);
    
    _delay_ms(5); // LCD store delay
}

void LCD_WriteString(uint8_t* str)
{
    //uint8_t i = 0;
    
    while(*str)
    {
        LCD_WriteChar(*str++);
        //i++;
    }
}


void LCD_Goto(uint8_t row, uint8_t col)
{
uint8_t pos[2] = {0x80 , 0xC0};

LCD_WriteCommand(pos[row]+col);

}

void LCD_Clear(void)
{
    LCD_WriteCommand(0x01);
}