/*
 * interrupts_Cfg.h
 *
 * Created: 8/19/2023 10:15:06 AM
 *  Author: DELL
 */ 


#ifndef INTERRUPTS_CFG_H_
#define INTERRUPTS_CFG_H_

#include "DIO.h"
#include <avr/interrupt.h>


#define NUMBER_OF_INTERRUPTS_TO_CONFIG	3

/******************************************************
			EXTERNAL INTERRUPTS_GLOBAL_ENABLE (GICR)
******************************************************/
#define GLOABL_INT0_EN					6
#define GLOBAL_INT1_EN					7
#define GLOABL_INT2_EN					5

/******************************************************
			EXTERNAL INTERRUPTS_FLAG_CLEARS (GIFR)
******************************************************/
#define GLOABL_INT0_FLAG				6
#define GLOBAL_INT1_FLAG				7
#define GLOABL_INT2_FLAG				5

/******************************************************
			GLOBAL INTERRUPTS (SREG)
******************************************************/
#define  GLOBAL_INTERRUPT				GLOBAL_INTERRUPT_ENABLE


#define GLOBAL_INTERRUPT_ENABLE			1
#define GLOABL_INTERRUPT_DISABLE		0


#endif /* INTERRUPTS_CFG_H_ */