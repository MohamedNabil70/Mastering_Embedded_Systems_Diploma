/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : It is required to Configure Board to Enable clock to port A
 *                   and toggle pin 13 every specific time

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

// register address
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800


#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)



#define RCC_CR      *(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_CFGR    *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)


int main(void)
{

//Enable clock to port A

/*Bit 2 IOPAEN: I/O port A clock enable
Set and cleared by software.
0: I/O port A clock disabled
1:I/O port A clock enabled      	*/

	RCC_APB2ENR |= 1<<2;


//Init GPIOA
GPIOA_CRH  &= 0xFF0FFFFF;
GPIOA_CRH  |= 0x00200000;
while(1)
{
GPIOA_ODR |= 1<<13 ;
for (int i = 0; i < 5000; i++); // arbitrary delay
GPIOA_ODR &= ~(1<<13) ;
for (int i = 0; i < 5000; i++); // arbitrary delay
}

return 0;
}
