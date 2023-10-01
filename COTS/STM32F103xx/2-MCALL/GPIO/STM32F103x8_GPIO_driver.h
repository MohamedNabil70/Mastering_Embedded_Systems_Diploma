/**************************************************
 * STM32F103x8_GPIO_driver.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 *
 **************************************************
 * This is GPIO Peripheral driver for STM32F103x8 MCU according to LQFP48 Package Specifications
 */

#ifndef INC_STM32F103x8_GPIO_DRIVER_H_
#define INC_STM32F103x8_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

//pinConfigure type
typedef struct{

	uint16_t GPIO_PinNumber; // Specifies the GPIO pins to be configured.
							// This parameter must be a value of @ref GPIO_PINS_define

	uint8_t GPIO_Mode;   // Specifies the operating mode for the selected pins
						// This parameter can be a value of @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed; // Specifies the speed for the selected pins
							  // This parameter can be a value of @ref GPIO_SPEED_define

}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PIN_state

#define  GPIO_PIN_HIGH		1
#define  GPIO_PIN_LOW	    0

//@ref GPIO_PINS_define

#define GPIO_PIN_0			((uint16_t)0b0000000000000001) /*Pin 0   Selected*/
#define GPIO_PIN_1			((uint16_t)0b0000000000000010) /*Pin 1	 Selected*/
#define GPIO_PIN_2			((uint16_t)0b0000000000000100) /*Pin 2	 Selected*/
#define GPIO_PIN_3			((uint16_t)0b0000000000001000) /*Pin 3	 Selected*/
#define GPIO_PIN_4			((uint16_t)0b0000000000010000) /*Pin 4	 Selected*/
#define GPIO_PIN_5			((uint16_t)0b0000000000100000) /*Pin 5	 Selected*/
#define GPIO_PIN_6			((uint16_t)0b0000000001000000) /*Pin 6	 Selected*/
#define GPIO_PIN_7			((uint16_t)0b0000000010000000) /*Pin 7	 Selected*/
#define GPIO_PIN_8			((uint16_t)0b0000000100000000) /*Pin 8	 Selected*/
#define GPIO_PIN_9			((uint16_t)0b0000001000000000) /*Pin 9	 Selected*/
#define GPIO_PIN_10			((uint16_t)0b0000010000000000) /*Pin 10	 Selected*/
#define GPIO_PIN_11			((uint16_t)0b0000100000000000) /*Pin 11	 Selected*/
#define GPIO_PIN_12			((uint16_t)0b0001000000000000) /*Pin 12	 Selected*/
#define GPIO_PIN_13			((uint16_t)0b0010000000000000) /*Pin 13	 Selected*/
#define GPIO_PIN_14			((uint16_t)0b0100000000000000) /*Pin 14	 Selected*/
#define GPIO_PIN_15			((uint16_t)0b1000000000000000) /*Pin 15	 Selected*/


//@ref GPIO_MODE_define
/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up resistnce
3: Input with pull-down resistnce
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function Input
*/

#define GPIO_MODE_ANALOG             0x00000000u 	//Analog mode
#define GPIO_MODE_INPUT_FLO          0x00000001u 	//Floating input
#define GPIO_MODE_INPUT_PU           0x00000002u 	//Input with pull-up resistance
#define GPIO_MODE_INPUT_PD           0x00000003u 	//Input with pull-down resistance
#define GPIO_MODE_OUTPUT_PP          0x00000004u 	//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD          0x00000005u 	//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP       0x00000006u 	//Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD       0x00000007u 	//Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT			 0x00000008u 	//Alternate function INPUT


//@ref GPIO_SPEED_define
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
*/
#define GPIO_SPEED_10M		0x00000001u 	//Output mode, max speed 10 MHz
#define GPIO_SPEED_2M		0x00000002u		//Output mode, max speed 2 MHz
#define GPIO_SPEED_50M		0x00000003u		//Output mode, max speed 50 MHz

//@REF GPIO_LOCK_STATE
#define GPIO_LOCK_ENABLED		1
#define GPIO_LOCK_ERROR	 	    0


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_GPIO_Init			(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig );
void MCAL_GPIO_DeInit		(GPIO_t* GPIOx);

//Read APIs
uint8_t MCAL_GPIO_ReadPin		(GPIO_t* GPIOx,uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort		(GPIO_t* GPIOx);

//Write APIs
void MCAL_GPIO_WritePin		(GPIO_t* GPIOx,uint16_t PinNumber,uint8_t value);
void MCAL_GPIO_WritePort	(GPIO_t* GPIOx,uint16_t value);

void MCAL_GPIO_TogglePin	(GPIO_t* GPIOx,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin		(GPIO_t* GPIOx,uint16_t PinNumber);

#endif /* INC_STM32F103x8_GPIO_DRIVER_H_ */
