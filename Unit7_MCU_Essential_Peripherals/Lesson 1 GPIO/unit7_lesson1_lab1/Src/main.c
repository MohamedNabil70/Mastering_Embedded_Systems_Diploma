/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit7_Lesson1_Lab1
 *
 *
 *   It is required to Configure The GPIO in STM32F103C8T6 BluePill Board to
 *   Read Data From External Push Buttons and Turn on LEDs corresponding to (Pressing)
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

//Defines
#define GET_BIT(REG,BIT) ((REG & (1<<BIT)) >> BIT)


/* Register addresses*/


//GPIOA Registers
#define GPIOA_BASE 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

//GPIOB Registers
#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_IDR *(volatile uint32_t *)(GPIOB_BASE + 0x08)
#define GPIOB_ODR *(volatile uint32_t *)(GPIOB_BASE + 0x0C)


//RCC Registers
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)



void clock_init(void){

	//Enable clock to port A
	RCC_APB2ENR |= 1<<2;
	//Enable clock to port B
	RCC_APB2ENR |= 1<<3;

}


void GPIO_init(void){

	/*Init GPIOA*/
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_ODR = 0;

	//PA1 Floating Input
	GPIOA_CRL  &= ~(0b11 << 4);
	GPIOA_CRL  |= (0b01 << 6);
	//PA13 Floating Input
	GPIOA_CRH  &= ~(0b11 << 20);
	GPIOA_CRH  |= (0b01 << 22);

	/*Init GPIOB*/
	GPIOB_ODR  = 0x0;

	//PB1 Push-pull Output [Max speed 10MHz]
	GPIOB_CRL |= (0b01<<4);
	GPIOB_CRL &= ~(0b11<<6);
	//PB13 Push-pull Output [Max speed 10MHz]
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);

}

void delay(int count){

	int i;
	for(i=0 ; i<count; i++);

}


int main(void)
{

	//initializations
	clock_init();
	GPIO_init();

	while(1)
	{

		//Check if PA13 is pressed (external Pull down)
		if(GET_BIT(GPIOA_IDR,13) == 1){ //Multi press
			//Turn on led on PB13
			GPIOB_ODR ^= 1<<13;
		}

		//Check if PA1 is pressed (external Pull up)
		if(GET_BIT(GPIOA_IDR,1) == 0){ //Single pressed

			//Turn on led on PB1
			GPIOB_ODR ^= 1<<1;
			//Trap processor until button not pressed
			while(GET_BIT(GPIOA_IDR,1) == 0);
		}



		delay(1000);

	}

}
