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
 * v1.1       29 Feb, 2024	Barakat S. Muharib		  unify GPIO Pins for all registers
*********************************************/

// Header Guard File
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

//GPIO PORT Name 
#define GPIO_PORTA 		        0
#define GPIO_PORTB 		        1
#define GPIO_PORTC 		        2

// GPIO Pins 
#define GPIO_PIN0         	            0
#define GPIO_PIN1         	            1
#define GPIO_PIN2         	            2
#define GPIO_PIN3         	            3
#define GPIO_PIN4         	            4
#define GPIO_PIN5         	            5
#define GPIO_PIN6         	            6
#define GPIO_PIN7         	            7
#define GPIO_PIN8         	            8
#define GPIO_PIN9         	            9
#define GPIO_PIN10         	            10
#define GPIO_PIN11        	            11
#define GPIO_PIN12        	            12
#define GPIO_PIN13        	            13
#define GPIO_PIN14        	            14
#define GPIO_PIN15        	            15

// GPIO_MODER Mode for Pin
#define GPIO_MODER_PIN_INPUT		0b00
#define GPIO_MODER_PIN_OUTPUT		0b01
#define GPIO_MODER_PIN_AF			0b10
#define GPIO_MODER_PIN_ANALOG		0b11

// GPIO_MODER Mode for the whole Port
#define GPIO_MODER_PORT_INPUT		0x00000000
#define GPIO_MODER_PORT_OUTPUT		0x55555555
#define GPIO_MODER_PORT_AF			0xAAAAAAAA
#define GPIO_MODER_PORT_ANALOG		0xFFFFFFFF

// GPIO_OTYPER Output Mode for Pin    
#define GPIO_OTYPER_PIN_PUSH_PULL 		0
#define GPIO_OTYPER_PIN_OPEN_DRAIN 	    1

// GPIO_OTYPER Output Mode for Port    
#define GPIO_OTYPER_PORT_PUSH_PULL 		0x00000000
#define GPIO_OTYPER_PORT_OPEN_DRAIN 	0x0000FFFF

// GPIO_OSPEEDR Mode for Pin
#define GPIO_OSPEEDR_PIN_LOW_SPEED		        0b00
#define GPIO_OSPEEDR_PIN_MED_SPEED		        0b01
#define GPIO_OSPEEDR_PIN_HIGH_SPEED             0b10
#define GPIO_OSPEEDR_PIN_VERY_HIGH_SPEED		0b11

// GPIO_OSPEEDR Mode for Port
#define GPIO_OSPEEDR_PORT_LOW_SPEED		        0x00000000
#define GPIO_OSPEEDR_PORT_MED_SPEED		        0x55555555
#define GPIO_OSPEEDR_PORT_HIGH_SPEED            0xAAAAAAAA
#define GPIO_OSPEEDR_PORT_VERY_HIGH_SPEED		0xFFFFFFFF

// Output Value(0 or 1) of the corresponding Pin  in the GPIO_ODR 
#define GPIO_OUTPUT_PIN_VALUE_ZERO  0
#define GPIO_OUTPUT_PIN_VALUE_ONE   1

// Output Value(0 or 1) of the whole Port  in the GPIO_ODR 
#define GPIO_OUTPUT_PORT_VALUE_ZERO 0x00000000
#define GPIO_OUTPUT_PORT_VALUE_ONE 	0x0000FFFF

// GPIO_PUPDR Pin State
#define GPIO_PUPDR_PIN_FLOAT	        0b00
#define GPIO_PUPDR_PIN_PULL_UP	        0b01
#define GPIO_PUPDR_PIN_PULL_DOWN        0b10

// GPIO_PUPDR Port State
#define GPIO_PUPDR_PORT_FLOAT	        0x00000000
#define GPIO_PUPDR_PORT_PULL_UP	        0x55555555
#define GPIO_PUPDR_PORT_PULL_DOWN       0xAAAAAAAA

// Prototype Functions for the GPIO Pin
void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputMode);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OSpeedMode);
void MGPIO_voidSetPinOutputValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutputValue);
void MGPIO_voidSetPullupDownResister(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullupDownState);
u8 MGPIO_u8GetInputPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void MGPIO_voidLockPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

// Prototype Functions for the whole GPIO PORT
void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32Mode);
void MGPIO_voidSetPortOutputMode(u8 Copy_u8PortName, u32 Copy_u32PortOutputMode);
void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32OSpeedMode);
void MGPIO_voidSetPortOutputValue(u8 Copy_u8PortName, u32 Copy_u32OutputValue);
void MGPIO_voidSetPortPullupDownResister(u8 Copy_u8PortName, u32 Copy_u32PullupDownState);
u32  MGPIO_u32GetInputPortValue(u8 Copy_u8PortName);
void MGPIO_voidLockPort(u8 Copy_u8PortName);

#endif
