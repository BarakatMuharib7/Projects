#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"


#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"

void main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	while(1)
	{
		MGPIO_voidSetPinMode(GPIO_PORTA, 		GPIO_PIN0, GPIO_MODER_PIN_OUTPUT);
		MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN0, GPIO_OSPEEDR_PIN_LOW_SPEED );
		MGPIO_voidSetPinOutputValue(GPIO_PORTA, GPIO_PIN0 , GPIO_OUTPUT_PIN_VALUE_ONE );


	}

}



