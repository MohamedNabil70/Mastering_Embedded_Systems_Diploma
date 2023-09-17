/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit6_Lesson4_Lab2
 *
 *
 *   It is required to Configure Board to run and enable Ext Interrupt for Stm32F103C6
 *   Read GPIO Port A pin 0 and according to its status (rising edge) toggle GPIO Port A pin 13
 *   Using EXTI Line0 interrupt with suitable embedded code.
 ******************************************************************************

 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//Learn-in-depth
//supervision ENG:Keroles Shenouda
//Mastering_Embedded System online diploma

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef volatile unsigned int vuint32_t ;

// Register addresses


//GPIOA Registers
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

//AFIO Registers
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)


//RCC Registers
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

//EXTI Registers
#define EXTI_BASE 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_BASE + 0x14)

//NVIC Registers
#define NVIC_EXTIE0 *(volatile uint32_t *)(0XE000E100)


void clock_init(void){

	//Enable clock to port A
	RCC_APB2ENR |= 1<<2;

	//Enable Alternate function I/O clock
	RCC_APB2ENR |= 1<<0;

}


void IO_init(void){

	/*Init GPIOA*/

	//Pin 13 Output
	GPIOA_CRH  &= 0xFF0FFFFF;
	GPIOA_CRH  |= 0x00200000;
	//Pin 0 Floating Input
	GPIOA_CRL |= (1<<2) ;

	//init AFIO EXTI0[3:0] 0000: PA[x] pin
	AFIO_EXTICR1 &= ~(0b1111 << 0);
}

void EXTI0_init(void){

	//Enable EXTI Line 	0
	EXTI_IMR |= 1<<0;

	//Rising trigger enabled for Line 0
	EXTI_RTSR |= 1<<0;

	//Enable NVIC irq6 >>> (EXTI0)
	NVIC_EXTIE0 |= 1<<6;

}

void EXTI0_IRQHandler(void){

	//Toggle LED on pin 13
	GPIOA_ODR ^= 1<<13 ;

	//clear pending interrupt (W1C)
	if((EXTI_PR & (1<<0) ) >> 0 )
	EXTI_PR |= 1<<0;

}

int main(void)
{

	//initializations
	clock_init();
	IO_init();
	EXTI0_init();


	while(1);
}
