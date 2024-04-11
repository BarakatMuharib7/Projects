/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		29 Mar, 2024
 * Version:				v2.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  29 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
 * v2.0		  04 April, 2024	Barakat S. Muharib		  Add New API
 *                                                        - MEXTI_voidInit
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"


// Array Of Pointers to Function
static void (*EXTI_pNotificationFunction[16])(void) = {NULLPTR};


// Task
void MEXTI_voidInit(void)
{
    // select the source input for the EXTI7 to EXTI0
    #if EXTI7_0_SRC_INPUT == EXTI_PORTA
		SYSCFG_EXTICR1 |= 0;
		SYSCFG_EXTICR2 |= 0;
    #elif EXTI7_0_SRC_INPUT == EXTI_PORTB
		SYSCFG_EXTICR1 |= 0X1111;
		SYSCFG_EXTICR2 |= 0X1111;
    #else
        #error "EXTI7_0_SRC_INPUT Configuration Error"
    #endif

}

void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    SET_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    CLR_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal)
{
    switch(Copy_tSenseSignal)
    {
        case MEXTI_RISING:
            CLR_BIT(EXTI->FTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
        break;

        case MEXTI_FALLING:
            CLR_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        case MEXTI_ONCHANGE:
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        default:
        break;
    }
}

void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void))
{

	EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
}

// ISR For EXTI0
void EXTI0_IRQHandler(void)
{
    // if(EXTI0_pNotificationFunction != NULLPTR)
    if(EXTI_pNotificationFunction[0] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[0]();
    }
    else
    {
        // Do Nothing
    }

    /*Falg Clearance */
    SET_BIT(EXTI->PR, 0);
}

// ISR For EXTI1
void EXTI1_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[1] != NULLPTR)
    {
        EXTI_pNotificationFunction[1]();
    }
    else
    {
        // Do Nothing
    }

    /*Falg Clearance */
    SET_BIT(EXTI->PR, 1);
}


