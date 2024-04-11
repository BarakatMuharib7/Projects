#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"




void main(void)
{
	// Initialize the system clock
	RCC_voidInit();
	// Enable Peripheral clock für GPIOA
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN );
//	// Set PA0 to be output
//	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0, GPIO_MODE_OUTPUT);
	MGPIO_voidSetPortMode(GPIO_PORTA, GPIO_MODE_OUTPUT_PORT);
//	// Set PA0 to be output Push Pull
//	MGPIO_voidSetPinOutputType(GPIO_PORTA,GPIO_PIN0, GPIO_OUTPUT_PP );
	MGPIO_voidSetPortOutputType(GPIO_PORTA, GPIO_OTYPER_PORT_PUSH_PULL);
//	// Set PA0 tb low speed
//	MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN0, GPIO_LOW_SPEED);
	MGPIO_voidSetPortOutputSpeed(GPIO_PORTA, GPIO_OSPEEDR_PORT_LOW_SPEED);
	// Initialize SysTick
	MSTK_voidInit();
	while(1)
	{
		int i;
//*********************Flash  Animation ************************
		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_HIGH);
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_LOW);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_HIGH);
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_LOW);
		MSTK_voidSetBusyWait(1000000);

//******************** Snake Animation ***************************
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 7; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN7 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 6; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN6 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 5; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN5 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 4; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN4 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 3; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN3 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 2; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN2 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		for (i = 0 ; i< 1; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN1 , GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);

		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_LOW);
		MSTK_voidSetBusyWait(1000000);

//*****************ping Pong Animation ************************************

		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
//		MSTK_voidSetBusyWait(1000000);
		for (i = 0 ; i< 7; i++)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i+1, GPIO_PIN_HIGH);
		}
		for (i = 7 ; i> 0; i--)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_LOW);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i-1, GPIO_PIN_HIGH);

		}
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
		MSTK_voidSetBusyWait(1000000);

//******************* Fata7y ya warda Animaion **************************

		for (i = 3 ; i> -1 ; i--)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, 7-i, GPIO_PIN_HIGH);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_HIGH);

		}

		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_LOW);
		MSTK_voidSetBusyWait(1000000);

//**********************  2afily ya warda ****************
		for (i = 7 ; i> 3 ; i--)
		{
			MSTK_voidSetBusyWait(1000000);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, 7-i, GPIO_PIN_HIGH);
			MGPIO_voidSetPinOutputValue(GPIO_PORTA, i, GPIO_PIN_HIGH);

		}

		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPortOutputValue(GPIO_PORTA, GPIO_PORT_LOW);
		MSTK_voidSetBusyWait(1000000);


	}
}
