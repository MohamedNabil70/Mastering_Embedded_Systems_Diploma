/*******************************************************
 * STM32F103x8_GPIO_driver.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 *******************************************************
 *   This is GPIO Peripheral driver for STM32F103x8 MCU according to LQFP48 Package Specifications
 */

#include "../STM32F103C8_Drivers/inc/STM32F103x8_GPIO_driver.h"

#include "../STM32F103C8_Drivers/inc/STM32F103x8.h"




/*
 * =============================================================================
 * 								Generic Functions
 * =============================================================================
 */


uint8_t Get_CRLH_Position(uint16_t PinNumber){

	switch(PinNumber)
	{
	//CRL Pins
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

		//CRH Pins
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}

	return 0;
}


/*
 * =============================================================================
 * 							API Functions Definitions
 * =============================================================================
 */






/**===============================================================================================
 * @FName			- MCAL_GPIO_Init
 * @Brief 			- Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @Parameter [in] 	- GPIOx: where x can be (A..E depending on the used device) to select the GPIO peripheral
 * @Parameter [in]	- PinConfig: a pointer to a GPIO_PinConfig_t structure that contains the configuration
 *								 information for the specified GPIO PIN
 * @Return Value	- NONE
 * Note				- STM32F103x8 MCU has GPIO A,B,C,D,E Modules
 *					  but LQFP48 Package has only GPIO A,B,a part of C/D
 *					  exported as external PINs from the MCU
 */
void MCAL_GPIO_Init(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig )
{

	//Port configuration register low (GPIOx_CRL) (x=A..G) FOR PINs 0 >> 7
	//Port configuration register high (GPIOx_CRH) (x=A..G)	FOR PINs 8 >> 16

	volatile uint32_t* configRegister = (PinConfig->GPIO_PinNumber <GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	volatile uint8_t pin_config =0;


	//clear CNFx[1:0] MODEx[1:0] [4 bits]
	(*configRegister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//check if selected mode is OUTPUT
	if((PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP ) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD)|| (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP)|| (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD) )
	{
		pin_config = ( (( (PinConfig->GPIO_Mode - 4) << 2 ) | (PinConfig->GPIO_Output_Speed)) & 0x0f) ;

	}
	else{ 	//configure pins if selected mode is INTPUT MODEx[1:0]=0x00


		if( (PinConfig->GPIO_Mode == GPIO_MODE_ANALOG) || (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO) ){

			pin_config = ( (( (PinConfig->GPIO_Mode ) << 2 ) | 0x00 ) & 0x0f) ;

		}else if(PinConfig->GPIO_Mode == GPIO_MODE_AF_INPUT){ //considered as floating input

			pin_config = ( (( (GPIO_MODE_INPUT_FLO) << 2 ) | 0x00 ) & 0x0f) ;

		}else{

			pin_config = ( (( (GPIO_MODE_INPUT_PU) << 2 ) | 0x00 ) & 0x0f) ;

			//to select between PullUp and PullDown modes
			if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU){

				//table 20.Port bit configuration table : PxODR -> 1
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);

			}else{
				//table 20.Port bit configuration table : PxODR -> 1
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}


	}

	//Set configRegister [CRL/CRH] PINs to the requires values
	(*configRegister) |= ( (pin_config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;
}


/**===============================================================================================
 * @FName			- MCAL_GPIO_DeInit
 * @Brief 			- Resets all GPIOx registers to the reset values
 * @Parameter [in] 	- GPIOx: x can be (A..E depending on the used device) to select the GPIO instant
 * @Return Value	- NONE
 * Note				- NONE
 */
void MCAL_GPIO_DeInit(GPIO_t* GPIOx)
{
	//Using the reset controller by modifying register APB2RSTR
	if (GPIOx == GPIOA){

		RCC->APB2RSTR |=  (1 << 2) ;  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1 << 2) ;

	}
	else if (GPIOx == GPIOB){

		RCC->APB2RSTR |=  (1 << 3) ;  //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1 << 3) ;

	}
	else if (GPIOx == GPIOC){

		RCC->APB2RSTR |=  (1 << 4) ;  //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1 << 4) ;

	}
	else if (GPIOx == GPIOD){

		RCC->APB2RSTR |=  (1 << 5) ;  //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1 << 5) ;

	}
	else{

		RCC->APB2RSTR |=  (1 << 6) ;  //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1 << 6) ;

	}

}




//Read APIs

/**================================================================================
 * @FName			- MCAL_GPIO_ReadPin
 * @Brief 			- Read Specific GPIO PIN
 * @Parameter [in] 	- GPIOx: x can be (A..E depending on the used device) to select the GPIO instant
 * @Parameter [in]	- PinNumber: choose pin Number according to @ref GPIO_PINS_define
 * @Return Value	- the Value on the chosen pin (one of two values according to @ref GPIO_PIN_state)
 * Note				- NONE
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_t* GPIOx,uint16_t PinNumber){

	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_LOW){

		return GPIO_PIN_HIGH;
	}else{

		return GPIO_PIN_LOW;
	}

}


/**================================================================================
 * @FName			- MCAL_GPIO_ReadPort
 * @Brief 			- Read Specific GPIO Port pin values
 * @Parameter [in] 	- GPIOx: x can be (A..E depending on the used device) to select the GPIO instant
 * @Return Value	- The chosen GPIO Port pin values
 * Note				- NONE
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_t* GPIOx){

	return (uint16_t)GPIOx->IDR;
}

//Write APIs

/**================================================================================
 * @FName			- MCAL_GPIO_WritePin
 * @Brief 			- Write value on a Specific GPIO PIN
 * @Parameter [in] 	- GPIOx: x can be (A..E depending on the used device) to select the GPIO instant
 * @Parameter [in]	- PinNumber: choose pin Number according to @ref GPIO_PINS_define
 * @Parameter [in]	- value: PIN value to be written
 * @Return Value	- NONE
 * Note				- NONE
 */
void MCAL_GPIO_WritePin(GPIO_t* GPIOx,uint16_t PinNumber,uint8_t value){

	//We can use ODR and Also we can use BSRR to reset and BRR to set pin value
	//i'm using BSRR to reset and BRR to set pin values

	if(value == (uint8_t)GPIO_PIN_HIGH){

		/*  Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Set the corresponding ODRx bit              */

		GPIOx->BSRR = (uint32_t)PinNumber;
	}else{

		/*	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Reset the corresponding ODRx bit				*/

		GPIOx->BRR = (uint32_t)PinNumber;
	}


}



/**================================================================================
 * @FName			- MCAL_GPIO_WritePort
 * @Brief 			- Write value on a Specific GPIO Port
 * @Parameter [in] 	- GPIOx: x can be (A..E depending on the used device) to select the GPIO instant
 * @Parameter [in]	- value: PORT value to be written
 * @Return Value	- NONE
 * Note				- NONE
 */
void MCAL_GPIO_WritePort(GPIO_t* GPIOx,uint16_t value){

	GPIOx->ODR = (uint32_t)value;
}



/**================================================================================
 * @FName			- MCAL_GPIO_TogglePin
 * @Brief 			- Toggle a Specific GPIO PIN
 * @Parameter [in] 	- GPIOx: x can be (A..E depinding on the used device) to select the GPIO instant
 * @Parameter [in]	- PinNumber: choose pin Number according to @ref GPIO_PINS_define
 * @Return Value	- NONE
 * Note				- NONE
 */
void MCAL_GPIO_TogglePin(GPIO_t* GPIOx,uint16_t PinNumber){

	GPIOx->ODR ^= (uint32_t)PinNumber;
}



/**================================================================================
 * @FName			- MCAL_GPIO_LockPin
 * @Brief 			- The locking mechanism allows the IO Configuration to be frozen
 * 					  Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH).
 *					  [cannot edit on pinConfig until GPIO clock is reset]
 *
 * @Parameter [in] 	- GPIOx: x can be (A..E depinding on the used device) to select the GPIO instant
 * @Parameter [in]	- PinNumber: choose pin Number according to @ref GPIO_PINS_define
 * @Return Value	- OK if pin Config is locked or an ERROR if pin isn't locked (defined @ref GPIO_LOCK_STATE)
 * Note				- NONE
 */
uint8_t MCAL_GPIO_LockPin(GPIO_t* GPIOx,uint16_t PinNumber){

	volatile uint32_t temp= 1<<16;

	// Bit 16 LCKK[16]: Lock key
	// This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	// 0: Port configuration lock key not active
	// 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	// LOCK key writing sequence:
	// Write 1
	// Write 0
	// Write 1
	// Read 0
	// Read 1 (this read is optional but confirms that the lock is active)
	//		Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//		Any error in the lock sequence will abort the lock.

	// Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	//write 1 in the selected pin
	GPIOx->LCKR |= (uint32_t)PinNumber;

	//Bit 16 LCKK[16]: Lock key Lock sequence:

	temp |= (uint32_t)PinNumber;
	// Write 1
	GPIOx->LCKR = temp;
	// Write 0
	GPIOx->LCKR = (uint32_t)PinNumber;
	// Write 1
	GPIOx->LCKR = temp;
	// Read 0
	temp = GPIOx->LCKR;
	// Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & (1<<16)))
	{
		return GPIO_LOCK_ENABLED;
	}else{
		return GPIO_LOCK_ERROR;
	}


}
