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
#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H

void HLEDMAT_voidInit(void);
void HLED_voidDisplay(u8 * Copy_pu8Data);
void voidDisableAllColumnsSR(void);
void voidSetRowsValueSR(u8 Copy_u8Value);


#endif
