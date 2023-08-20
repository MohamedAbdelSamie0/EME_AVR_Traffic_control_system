/*
 * Atmega32_Registers.h
 *
 * Created: 8/18/2023 9:29:18 AM
 *  Author: Mohamed Abdelsamie
 */ 


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

/******************************************************
				PORT REGISTERS
******************************************************/

#define PORTA	*((volatile uint8_t *) 0x3B)
#define PORTB	*((volatile uint8_t *) 0x38)
#define PORTC	*((volatile uint8_t *) 0x35)
#define PORTD	*((volatile uint8_t *) 0x32)

/******************************************************
			DIRECTION CONTROL REGISTERS
******************************************************/

#define DDRA	*((volatile uint8_t *) 0x3A)
#define DDRB	*((volatile uint8_t *) 0x37)
#define DDRC	*((volatile uint8_t *) 0x34)
#define DDRD	*((volatile uint8_t *) 0x31)

/******************************************************
				PIN REGISTERS
******************************************************/
#define PINA	*((volatile uint8_t *) 0x39)
#define PINB	*((volatile uint8_t *) 0x36)
#define PINC	*((volatile uint8_t *) 0x33)
#define PIND	*((volatile uint8_t *) 0x30)

/******************************************************
				EXTERNAL INTERRUPTS REGISTERS
******************************************************/
#define SREG	*((volatile uint8_t *) 0x5F)
#define MCUCR	*((volatile uint8_t *) 0x55)
#define MCUCSR	*((volatile uint8_t *) 0x54)
#define	GICR	*((volatile uint8_t *) 0x5B)
#define	GIFR	*((volatile uint8_t *) 0x5A)


#endif /* ATMEGA32_REGISTERS_H_ */