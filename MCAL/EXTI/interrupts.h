/*
 * interrupts.h
 *
 * Created: 8/19/2023 10:14:48 AM
 *  Author: DELL
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "interrupts_Cfg.h"

typedef enum
{
	EX_INT0 = 0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

typedef enum
{
	LOW_LEVEL = 0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef struct
{
	ExInterruptSource_type EXTI_source;
	TriggerEdge_type EXTI_trigger;
	uint8_t IRQ_en;
	uint8_t Flag_clear;
	
}EXTi_INTERRUPTconfiguration;

/**
 * @brief External Interrupt Enable
 * 
 * @param interrupt EX_INT0 - EX_INT1 - EX_INT2
 */
void EXTI_GlobalSet(void);

/**
 * @brief External Interrupt configure edge
 * 
 * @param interrupt EX_INT0 - EX_INT1 - EX_INT2
 * @param edge 	LOW_LEVEL - ANY_LOGIC_CHANGE - FALLING_EDGE - RISING_EDGE
 */
void EXTI_interruptconfig(EXTi_INTERRUPTconfiguration *config_struct);


#endif /* INTERRUPTS_H_ */