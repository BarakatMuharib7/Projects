/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		2 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  2 Mar, 2024	Barakat S. Muharib		  Initial Creation
*********************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/* AHB Clock =  16 MHz (RCC_CLK_HSI as clock source to MP) : 2 (RCC_AHB_DIV_2 as Pre Scaler)  = 8MHz 
 * AHB/8 is the  Clock source to the STK
 *  AHB / 8  = 1 MHz ==> 1 tick (clock) = 1 Mc Second
*/  
#define     STK_CLK_SRC     STK_AHB_DIV_8 
#define     STK_INT_CTRL    STK_ENABLE
#define     STK_CTRL        STK_DISABLE


#endif
