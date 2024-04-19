
/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		22 March, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				HAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  22 March, 2024	Barakat S. Muharib		  Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"

#include "../include/LEDMAT_interface.h"

u8  arr1[8] = {144, 74, 127, 218, 128, 0, 0, 0};
u8  arr2[8] = {144, 74, 127, 90, 128, 64, 0, 0};
u8  arr3[8] = {144, 74, 127, 218, 0, 0, 32, 0};
u8  arr4[8] = {144, 74, 127, 218, 0, 0, 0, 16};
u8  arr5[8] = {144, 74, 127, 218, 0, 0, 8, 0};
u8  arr6[8] = {144, 74, 127, 218, 0, 4, 0, 0};//*******´´´
u8  arr7[8] = {144, 74, 127, 218, 2, 0, 0, 0};

u8  arr8[8] =  {144, 72, 126, 203, 18, 0, 0, 0};// At the Head

u8  arr9[8] = {144, 74, 127, 218, 2, 0, 0, 0};
u8  arr10[8] =  {144, 74, 127, 218, 0, 4, 0, 0};//*****
u8  arr11[8] = {144, 74, 127, 218, 0, 0, 8, 0};
u8  arr12[8] =  {144, 74, 127, 218, 0, 0, 0, 16};
u8  arr13[8] = {144, 74, 127, 218, 0, 0, 32, 0};
u8  arr14[8] = {144, 74, 127, 90, 128, 64, 0, 0};

//************************************************
u8  arr15[8] =  {144, 74, 127, 218, 128, 0, 0, 0};
u8  arr16[8] =  {144, 74, 127, 90, 128, 64, 0, 0};
u8  arr17[8] =  {144, 74, 127, 218, 0, 32, 0, 0};

u8  arr18[8] =  {144, 74, 127, 218, 0, 16, 0, 0};

u8  arr19[8] = {144, 74, 127, 218, 0, 32, 0, 0};
u8  arr20[8] =  {144, 74, 127, 90, 128, 64, 0, 0};//(144, 74, 127, 90, 128, 64, 0, 0)

void main(void)
{
	//Initialize the SystemClock
	RCC_voidInit();
	/* Enable Peripheral Clock for GPIOA */
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	/* Enable Peripheral Clock for GPIOB */
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOBEN);
	// Initialize Systick
	MSTK_voidInit();
	// Initialize LED Matrix
	HLEDMAT_voidInit();
	// Print Your First Letter of your name on the LED Matrix
	u8  arr[8] = {0, 254, 146, 108, 0, 0, 0, 0};
	//HLED_voidDisplay(arr);

	while(1)
	{
		/*
		int i, j;
		for (i= 0 ; i<3 ; i++)
		{
			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr1);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr2);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr3);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr4);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr5);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr6);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr7);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr8);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr9);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr10);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr11);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr12);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr13);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr14);
			}

		}




		for (i= 0 ; i<3 ; i++)
		{
			////////////////////////////
			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr15);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr16);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr17);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr18);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr19);
			}

			for (j = 0 ; j <8; j++ )
			{
				HLED_voidDisplay(arr20);
			}


		}

		*/

		HLED_voidDisplay(arr);
	}
}



