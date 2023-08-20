/*
 * interrupts.c
 *
 * Created: 8/19/2023 10:15:18 AM
 *  Author: DELL
 */ 

#include "interrupts.h"


void EXTI_GlobalSet()
{
	#if	GLOBAL_INTERRUPT == GLOBAL_INTERRUPT_ENABLE
		SetBit(SREG, 7);
	#elif	GLOBAL_INTERRUPT == GLOABL_INTERRUPT_DISABLE
		ClearBit(SREG, 7);
	#endif
}

void EXTI_interruptconfig(EXTi_INTERRUPTconfiguration *config_struct)
{
	/*	enable gloabl interrupts	*/
	EXTI_GlobalSet();
	
		/*	enable external interrupt request	*/
		SetBit(GICR, config_struct->IRQ_en);
		
		switch(config_struct->EXTI_source)
		{
		/*	external interrupts trigger control	*/
		case EX_INT0:
			MCUCR |= config_struct->EXTI_trigger;
			break;
			
		case EX_INT1:
			MCUCR |= config_struct->EXTI_trigger << 2;
			break;
			
		case EX_INT2:
			if(config_struct->EXTI_trigger == FALLING_EDGE)
				ClearBit(MCUCSR, 6);
			else
				SetBit(MCUCSR, 6);
		}
	
}