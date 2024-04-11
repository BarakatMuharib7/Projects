/*********************************************
 * Author:				Barakat S. Muharib
 * Creation Data:		23 Feb, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Barakat S. Muharib		  Initial Creation
*********************************************/

// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/GPIO_interface.h"
# include "../include/GPIO_private.h"
# include "../include/GPIO_config.h"


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_MODER Setting 
			GPIOA_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_MODER Setting 
			GPIOB_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOB_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_MODER Setting 
			GPIOC_MODER &= ~(GPIO_MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOC_MODER |=  (Copy_u8Mode 	 << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}


void MGPIO_voidSetPinOutputMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputMode)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			if (Copy_u8OutputMode == GPIO_OTYPER_PIN_PUSH_PULL)
				CLR_BIT(GPIOA_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OTYPER_PIN_OPEN_DRAIN)
				SET_BIT(GPIOA_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		
		case GPIO_PORTB:
			if (Copy_u8OutputMode == GPIO_OTYPER_PIN_PUSH_PULL)
				CLR_BIT(GPIOB_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OTYPER_PIN_OPEN_DRAIN)
				SET_BIT(GPIOB_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		
		case GPIO_PORTC:
			if (Copy_u8OutputMode == GPIO_OTYPER_PIN_PUSH_PULL)
				CLR_BIT(GPIOC_OTYPER, Copy_u8PinNumber);
			else if (Copy_u8OutputMode == GPIO_OTYPER_PIN_OPEN_DRAIN)
				SET_BIT(GPIOC_OTYPER, Copy_u8PinNumber);
			else
			{
				// Error ;
			}
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OSpeedMode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_OSPEEDR Setting 
			GPIOA_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_OSPEEDR |=  (Copy_u8OSpeedMode 		<< (Copy_u8PinNumber * PIN_OFFSET));
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_OSPEEDR Setting 
			GPIOB_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOB_OSPEEDR |=  (Copy_u8OSpeedMode		<< (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_OSPEEDR Setting 
			GPIOC_OSPEEDR &= ~(GPIO_OSPEEDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOC_OSPEEDR |=  (Copy_u8OSpeedMode 	 	<< (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPinOutputValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputValue)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ONE)
                GPIOA_BSRR = (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ZERO)
                GPIOA_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;	
			}
		break;
		
		case GPIO_PORTB:
			if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ONE)
                GPIOB_BSRR = (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ZERO)
                GPIOB_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;	
			}
		break;
		
		case GPIO_PORTC:
			if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ONE)
                GPIOC_BSRR = (1 << Copy_u8PinNumber );
			else if (Copy_u8OutputValue == GPIO_OUTPUT_PIN_VALUE_ZERO)
                GPIOC_BSRR = (1 << (Copy_u8PinNumber + GPIO_BSRR_PIN_OFFSET_RESET));// go to the Reset Bit Position of the Pin
			else
			{
				// Error ;
			}
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPullupDownResister(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullupDownState)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_PUBDR Setting 
			GPIOA_PUPDR &= ~(GPIO_PUPDR_MASK 		<< (Copy_u8PinNumber * PIN_OFFSET));// Bitmasking
			GPIOA_PUPDR |=  (Copy_u8PullupDownState << (Copy_u8PinNumber * PIN_OFFSET));
		break;
		default:
		// Error
		break;
	}
}

u8 MGPIO_u8GetInputPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8BitValue = 0xFF;
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			Local_u8BitValue = GET_BIT(GPIOA_IDR, Copy_u8PinNumber);
		break;
		
		case GPIO_PORTB:
		
			Local_u8BitValue = GET_BIT(GPIOB_IDR, Copy_u8PinNumber);
		break;
		
		case GPIO_PORTC:
		
			Local_u8BitValue = GET_BIT(GPIOC_IDR, Copy_u8PinNumber);
		break;
		default:
		// Error
		break;
	}
	
	return Local_u8BitValue;
	
}

void MGPIO_voidLockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOA_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOA_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOA_LCKR = (GPIOA_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOA_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);

		break;
		
		case GPIO_PORTB:
			CLR_BIT(GPIOB_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOB_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOB_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOB_LCKR = (GPIOB_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOB_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
		break;
		
		case GPIO_PORTC:
			CLR_BIT(GPIOC_LCKR, GPIO_LCKK16);// unlock to let write to the Lockbit of Pin 
			SET_BIT(GPIOC_LCKR, Copy_u8PinNumber);
			//write in LCKK the sequence 1, 0, 1 keeping the Lockbit value of Pin unchanged
			GPIOC_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
			GPIOC_LCKR = (GPIOC_LCKR & ( ~(1<< GPIO_LCKK16))) | (1<< Copy_u8PinNumber);
			GPIOC_LCKR |=  (1<< GPIO_LCKK16) | (1<< Copy_u8PinNumber);
		break;
		default:
		// Error
		break;
	}
	
}

//********************* Functions for the whole Port Begin ***************************

void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32Mode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_MODER Setting 
			GPIOA_MODER  = GPIO_MODER_ZERO; 
			GPIOA_MODER |=  (Copy_u32Mode);
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_MODER Setting 
			GPIOB_MODER  = GPIO_MODER_ZERO;
			GPIOB_MODER |=  (Copy_u32Mode);
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_MODER Setting 
			GPIOC_MODER  = GPIO_MODER_ZERO;
			GPIOC_MODER |=  (Copy_u32Mode);
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputMode(u8 Copy_u8PortName, u32 Copy_u32PortOutputMode)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
				GPIOA_OTYPER = GPIO_OTYPER_ZERO;
				GPIOA_OTYPER |= Copy_u32PortOutputMode;
		break;
		
		case GPIO_PORTB:
				GPIOB_OTYPER = GPIO_OTYPER_ZERO;
				GPIOB_OTYPER |= Copy_u32PortOutputMode;;
		break;
		
		case GPIO_PORTC:
				GPIOC_OTYPER = GPIO_OTYPER_ZERO;
				GPIOC_OTYPER |= Copy_u32PortOutputMode;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32OSpeedMode)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// GPIOA_OSPEEDR Setting 
			GPIOA_OSPEEDR = GPIO_OSPEEDR_ZERO;
			GPIOA_OSPEEDR |= Copy_u32OSpeedMode;	
		break;
		
		case GPIO_PORTB:
			// GPIOB_OSPEEDR Setting 
			GPIOB_OSPEEDR = GPIO_OSPEEDR_ZERO;
			GPIOB_OSPEEDR |= Copy_u32OSpeedMode;
		break;
		
		case GPIO_PORTC:
			// GPIOC_OSPEEDR Setting 
			GPIOC_OSPEEDR = GPIO_OSPEEDR_ZERO;
			GPIOC_OSPEEDR |= Copy_u32OSpeedMode;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortOutputValue(u8 Copy_u8PortName, u32 Copy_u32OutputValue)
{

	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// GPIOA_ODR Setting 
			GPIOA_ODR = GPIO_ODR_ZERO;
			GPIOA_ODR |= Copy_u32OutputValue;	
		break;
		
		case GPIO_PORTB:
			// GPIOB_ODR Setting 
			GPIOB_ODR = GPIO_ODR_ZERO;
			GPIOB_ODR |= Copy_u32OutputValue;
		break;
		
		case GPIO_PORTC:
			// GPIOC_ODR Setting 
			GPIOC_ODR = GPIO_ODR_ZERO;
			GPIOC_ODR |= Copy_u32OutputValue;
		break;
		default:
		// Error
		break;
	}
}

void MGPIO_voidSetPortPullupDownResister(u8 Copy_u8PortName, u32 Copy_u32PullupDownState)
{
	
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			// GPIOA_PUBDR Setting 
			GPIOA_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOA_PUPDR |= (Copy_u32PullupDownState );
			
		break;
		
		case GPIO_PORTB:
		
			// GPIOB_PUBDR Setting 
			GPIOB_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOB_PUPDR |= (Copy_u32PullupDownState );
		break;
		
		case GPIO_PORTC:
		
			// GPIOC_PUBDR Setting 
			GPIOC_PUPDR  = (GPIO_PUPDR_ZERO );
			GPIOC_PUPDR |= (Copy_u32PullupDownState );
		break;
		default:
		// Error
		break;
	}
}

u32 MGPIO_u32GetInputPortValue(u8 Copy_u8PortName)
{
	u32 Local_u32PortValue  = 0xFFFF ;
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
		
			Local_u32PortValue = (GPIOA_IDR & GPIO_IDR_PORT_MASK);
		break;
		
		case GPIO_PORTB:
		
			Local_u32PortValue = (GPIOB_IDR & GPIO_IDR_PORT_MASK);
		break;
		
		case GPIO_PORTC:
		
			Local_u32PortValue = (GPIOC_IDR & GPIO_IDR_PORT_MASK);
		break;
		default:
		// Error
		break;
	}
	
	return Local_u32PortValue;
	
}

void MGPIO_voidLockPort(u8 Copy_u8PortName)
{
		switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOA_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOA_LCKR = (GPIOA_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOA_LCKR = (GPIOA_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOA_LCKR = (GPIOA_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;

		break;
		
		case GPIO_PORTB:
			CLR_BIT(GPIOB_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOB_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOB_LCKR = (GPIOB_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOB_LCKR = (GPIOB_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOB_LCKR = (GPIOB_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;
		break;
		
		case GPIO_PORTC:
			CLR_BIT(GPIOC_LCKR, GPIO_LCKK16);// unlock to let write to the LockPort
			GPIOC_LCKR &= GPIO_LCKR_PORT_LOCKED;
			//write in LCKK the sequence 1, 0, 1 keeping the LockPort value of Port unchanged
			GPIOC_LCKR = (GPIOC_LCKR | (1<< GPIO_LCKK16)) 	  & GPIO_LCKR_PORT_LOCKED;
			GPIOC_LCKR = (GPIOC_LCKR & ( ~(1<< GPIO_LCKK16))) & GPIO_LCKR_PORT_LOCKED;
			GPIOC_LCKR = (GPIOC_LCKR | (1<< GPIO_LCKK16))	  & GPIO_LCKR_PORT_LOCKED;
		break;
		default:
		// Error
		break;
	}
	
}
