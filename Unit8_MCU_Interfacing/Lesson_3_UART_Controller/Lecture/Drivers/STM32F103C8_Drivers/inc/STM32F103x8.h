/*
 * STM32F103x8.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

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

//NVIC Register Map
#define NVIC_BASE				(0XE000E100UL)
#define NVIC_ISER0				*(volatile uint32_t*)( NVIC_BASE + 0X00 )
#define NVIC_ISER1				*(volatile uint32_t*)( NVIC_BASE + 0X04 )
#define NVIC_ISER2				*(volatile uint32_t*)( NVIC_BASE + 0X08 )
#define NVIC_ICER0				*(volatile uint32_t*)( NVIC_BASE + 0X80 )
#define NVIC_ICER1				*(volatile uint32_t*)( NVIC_BASE + 0X84 )
#define NVIC_ICER2				*(volatile uint32_t*)( NVIC_BASE + 0X88 )

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


#define USART1_BASE 							0X40013800UL

//-----------------------------
//Base Addresses for APB1 BUS Peripherals
//-----------------------------

#define USART2_BASE 							0X40004400UL
#define USART3_BASE 							0X40004800UL


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
	volatile uint32_t EXTICR[4]	;
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
//Peripheral registers: USART
//-*-*-*-*-*-*-*-*-*-*-*


typedef struct {

	volatile uint32_t SR	;
	volatile uint32_t DR	;
	volatile uint32_t BRR	;
	volatile uint32_t CR1	;
	volatile uint32_t CR2	;
	volatile uint32_t CR3	;
	volatile uint32_t GTPR	;

}USART_t;


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


#define USART1			((USART_t *)USART1_BASE)
#define USART2			((USART_t *)USART2_BASE)
#define USART3			((USART_t *)USART3_BASE)



/*************************************************************************************/

//-*-*-*-*-*-*-*-*-*-*-*-
//Clock Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_AFIO_CLK_EN()   (RCC->APB2ENR |= (1<<0))

#define RCC_GPIOA_CLK_EN()   (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()   (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()   (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()   (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()   (RCC->APB2ENR |= (1<<6))

//USART Clock Enable
#define RCC_USART1_CLK_EN()   (RCC->APB2ENR |= (1<<14))
#define RCC_USART2_CLK_EN()   (RCC->APB1ENR |= (1<<17))
#define RCC_USART3_CLK_EN()   (RCC->APB1ENR |= (1<<18))


//USART Clock RESET
#define RCC_USART1_CLK_RESET()   (RCC->APB2RSTR |= (1<<14))
#define RCC_USART2_CLK_RESET()   (RCC->APB1RSTR |= (1<<17))
#define RCC_USART3_CLK_RESET()   (RCC->APB1RSTR |= (1<<18))


/*************************************************************************************/


//-*-*-*-*-*-*-*-*-*-*-*-
//IVT Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40

#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39


//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//EXTI
#define NVIC_IRQ6_EXTI0_ENABLE()				(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_ENABLE()				(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_ENABLE()				(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_ENABLE()				(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_ENABLE()				(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_ENABLE()				(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_ENABLE()			(NVIC_ISER1 |= 1<<8)  //40-32 = 8


#define NVIC_IRQ6_EXTI0_DISABLE()				(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_DISABLE()				(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_DISABLE()				(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_DISABLE()				(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_DISABLE()				(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_DISABLE()			(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_DISABLE()			(NVIC_ICER1 |= 1<<8)  //40-32 = 8


//USART
#define NVIC_IRQ37_USART1_ENABLE()				(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))  //37-32
#define NVIC_IRQ38_USART2_ENABLE()				(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))  //38-32
#define NVIC_IRQ39_USART3_ENABLE()				(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))  //39-32

#define NVIC_IRQ37_USART1_DISABLE()				(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))  //37-32
#define NVIC_IRQ38_USART2_DISABLE()				(NVIC_ICER1 |= 1<<(USART2_IRQ - 32))  //38-32
#define NVIC_IRQ39_USART3_DISABLE()				(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))  //39-32


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32F103X8_H_ */
