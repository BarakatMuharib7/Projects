#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"


#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/MyArray.h"


void main(void)
{
	/*Initialize system clock*/
	RCC_voidInit();
	/*Enable Peripheral clock for GPIOA*/
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);

	/*Initialize PA0 to PA7 to be output pins*/
	MGPIO_voidSetPortMode(GPIO_PORTA,GPIO_MODE_OUTPUT_PORT);
	MGPIO_voidSetPortOutputType(GPIO_PORTA, GPIO_OTYPER_PORT_PUSH_PULL);
	MGPIO_voidSetPortOutputSpeed(GPIO_PORTA, GPIO_OSPEEDR_PORT_LOW_SPEED);

	u32 Local_LoopCounter = 0;
	while(1)
	{
		u8 Local_u8Delay_micros;
		for (Local_LoopCounter = 0; Local_LoopCounter < 132125 ; Local_LoopCounter++)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GET_BIT(Fadia1_raw[Local_LoopCounter], 0));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GET_BIT(Fadia1_raw[Local_LoopCounter], 1));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GET_BIT(Fadia1_raw[Local_LoopCounter], 2));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GET_BIT(Fadia1_raw[Local_LoopCounter], 3));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN4,GET_BIT(Fadia1_raw[Local_LoopCounter], 4));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN5,GET_BIT(Fadia1_raw[Local_LoopCounter], 5));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN6,GET_BIT(Fadia1_raw[Local_LoopCounter], 6));
			MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN7,GET_BIT(Fadia1_raw[Local_LoopCounter], 7));

			/* 160 micro seconds delay*/
			for (Local_u8Delay_micros =0 ; Local_u8Delay_micros<160 ; Local_u8Delay_micros++  )
			{
				asm ("NOP");// 1 micro Second
			}
		}

	 	;
	}
}


