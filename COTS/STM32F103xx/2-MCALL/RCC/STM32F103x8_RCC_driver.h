/**************************************************
 * STM32F103x8_RCC_driver.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 *
 **************************************************
 * This is RCC Peripheral driver for STM32F103x8 MCU according to LQFP48 Package Specifications
 */

#ifndef INC_STM32F103x8_RCC_driver_H_
#define INC_STM32F103x8_RCC_driver_H_

//-----------------------------
//Includes
//-----------------------------

#include "../../STM32F103C8_Drivers/inc/STM32F103x8.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8_GPIO_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

#define HSE_CLOCK 			(uint32_t)16000000
#define HSI_RC_CLOCK 		(uint32_t)8000000



//-----------------------------
//Macros Configuration References
//-----------------------------




/*
 * ===============================================
 * APIs
 * ===============================================
 */


uint32_t MCAL_RCC_GetSYSCLKFreq(void); //get SYSCLK bus Frequency

uint32_t MCAL_RCC_GetHCLKFreq(void); //get AHB bus Frequency
uint32_t MCAL_RCC_GetPCLK1Freq(void); //get APB1 bus Frequency
uint32_t MCAL_RCC_GetPCLK2Freq(void); //get APB2 bus Frequency




#endif /* INC_STM32F103x8_RCC_driver_H_ */
