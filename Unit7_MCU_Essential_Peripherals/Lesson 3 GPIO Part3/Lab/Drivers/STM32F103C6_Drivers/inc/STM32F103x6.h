/*
 * STM32F103x6.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdint.h>
#include <stdlib.h>

/*************************************************************************************/

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE						0X08000000UL
#define SYSTEM_MEMORY_BASE						0X1FFFF000UL
#define SRAM_MEMORY_BASE						0X20000000UL

#define PERIPHERALS_BASE						0X40000000UL
#define CORETEX_M3_INTERNAL_PERIPHERALS_BASE	0XE0000000UL

/*************************************************************************************/


/*-------------------------------------------*
** Base Addresses for SYSTEM BUS Peripherals *
**-------------------------------------------*/


//-----------------------------
//Base Addresses for AHP BUS Peripherals
//-----------------------------

//RCC
#define RCC_BASE 								0X40021000UL


//-----------------------------
//Base Addresses for APB2 BUS Peripherals
//-----------------------------

/*GPIO*/
//A,B Fully included in LQFP48 Package
#define GPIOA_BASE 								0X40010800UL
#define GPIOB_BASE 								0X40010C00UL

//C,D Partially included in LQFP48 Package
#define GPIOC_BASE 								0X40011000UL
#define GPIOD_BASE 								0X40011400UL

//E Not included in LQFP48 Package
#define GPIOE_BASE 								0X40011800UL

/***************/

//AFIO
#define AFIO_BASE 								0X40010000UL

//EXTI
#define EXTI_BASE 								0X40010400UL

//-----------------------------
//Base Addresses for APB1 BUS Peripherals
//-----------------------------


/*************************************************************************************/

/*-------------------------------------------*
**     Peripherals Registers typedef         *
**-------------------------------------------*/

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t CR 		;
	volatile uint32_t CFGR	 	;
	volatile uint32_t CIR	 	;
	volatile uint32_t APB2RSTR	;
	volatile uint32_t APB1RSTR	;
	volatile uint32_t AHBENR 	;
	volatile uint32_t APB2ENR	;
	volatile uint32_t APB1ENR	;
	volatile uint32_t BDCR		;
	volatile uint32_t CSR		;

}RCC_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t CRL	;
	volatile uint32_t CRH	;
	volatile uint32_t IDR	;
	volatile uint32_t ODR	;
	volatile uint32_t BSRR	;
	volatile uint32_t BRR	;
	volatile uint32_t LCKR	;

}GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t EVCR		;
	volatile uint32_t MAPR		;
	volatile uint32_t EXTICR1	;
	volatile uint32_t EXTICR2	;
	volatile uint32_t EXTICR3	;
	volatile uint32_t EXTICR4	;
	volatile uint32_t RESERVED0	;
	volatile uint32_t MAPR2		;

}AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t IMR	;
	volatile uint32_t EMR	;
	volatile uint32_t RTSR	;
	volatile uint32_t FTSR	;
	volatile uint32_t SWIER	;
	volatile uint32_t PR	;

}EXTI_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers:
//-*-*-*-*-*-*-*-*-*-*-*

/*
typedef struct {

	volatile uint32_t ;
	volatile uint32_t ;
	volatile uint32_t ;
	volatile uint32_t ;
	volatile uint32_t ;

};
*/


/*************************************************************************************/


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC				((RCC_t *)RCC_BASE)

#define GPIOA			((GPIO_t *)GPIOA_BASE)
#define GPIOB			((GPIO_t *)GPIOB_BASE)
#define GPIOC			((GPIO_t *)GPIOC_BASE)
#define GPIOD			((GPIO_t *)GPIOD_BASE)
#define GPIOE			((GPIO_t *)GPIOE_BASE)

#define AFIO			((AFIO_t *)AFIO_BASE)

#define EXTI			((EXTI_t *)EXTI_BASE)



/*************************************************************************************/

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR |= (1<<0))

#define RCC_GPIOA_CLK_EN()   (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()   (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()   (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()   (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()   (RCC->APB2ENR |= (1<<6))



/*************************************************************************************/


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32F103X6_H_ */
