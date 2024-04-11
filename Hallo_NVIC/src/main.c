/*
 * main.c
 *
 *  Created on: 18 Mar 2024
 *      Author: barak
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/NVIC_interface.h"

void main(void)
{
	/* Initialize the System Clock */
	RCC_voidInit();
	/* Enable Peripheral Clock for GPIOA */
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);

	/* Set PA0 to be output and low speed */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputType(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PP);
	MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN0, GPIO_LOW_SPEED);
	/* Set PA1 to be output and low speed */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputType(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PP);
	MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN1, GPIO_LOW_SPEED);

	/* Initialize the Group and Sub Prio bits in INVIC*/
	MNVIC_voidInit();
	/* Enable the Interrupt for EXTI0 */
	MNVIC_voidPeripheralInterruptControl(6 ,MNVIC_INT_ENABLE);
	/* Enable the Interrupt for EXTI1 */
	MNVIC_voidPeripheralInterruptControl(7 ,MNVIC_INT_ENABLE);
	/* Set the Priority for EXTI0 */
	MNVIC_voidSetPeripheralPriority(6, 0b0010);//EXTI0:  GRB 0 SUB 2
	/* Set the Priority for EXTI1 */
	MNVIC_voidSetPeripheralPriority(7, 0b0000);//EXTI1:  GRB 0 SUB o
	/* Fire EXTI0 Interrupt, Set Pending Flag for EXT0*/
	MNVIC_voidSetPendingFlag(6);
	asm("NOP");
	while(1)
	{


	}
}

void EXTI0_IRQHandler(void)
{
	MNVIC_voidSetPendingFlag(7);
	static u8 Local_u8_LEDState = 0;
	Local_u8_LEDState ^= 0;
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, Local_u8_LEDState );
}

void EXTI1_IRQHandler(void)
{

	static u8 Local_u8_LEDState = 0;
	Local_u8_LEDState ^= 0;
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, Local_u8_LEDState );

}
