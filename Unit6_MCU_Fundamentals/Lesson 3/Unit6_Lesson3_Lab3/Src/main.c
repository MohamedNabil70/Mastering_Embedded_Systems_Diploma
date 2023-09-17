/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit6_Lesson3_Lab3
 *
 *
 *   It is required to Configure Board to run with the
 	 	 Following rates:
		- APB1 Bus frequency 16 MHZ
		- APB2 Bus frequency 8 MHZ
		- AHB frequency 32 MHZ
		- SysClk 32 MHZ
		- Use only internal HSI_RC
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

/* Bit 0 HSION: Internal high-speed clock enable
Set and cleared by software.
Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
mode or in case of failure of the external 3-25 MHz oscillator used directly or indirectly as
system clock. This bit can not be cleared if the internal 8 MHz RC is used directly or
indirectly as system clock or is selected to become the system clock.
0: Internal 8 MHz RC oscillator OFF
1: Internal 8 MHz RC oscillator ON      */

		RCC_CR |= (1<<0);


/*Bits 21:18 PLLMUL[3:0]: PLL multiplication factor
These bits are written by software to define the PLL multiplication factor. They can be written only
when PLL is disabled.
000x: Reserved
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8 */

		RCC_CFGR |= (0b0110 <<18);

/*Bit 24 PLLON: PLL enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
PLL clock is used as system clock or is selected to become the system clock. Software
must disable the USB OTG FS clock before clearing this bit.
0: PLL OFF
1: PLL ON   */

		RCC_CR |= (1<<24);

/*Bits 1:0 SW[1:0]: System clock Switch
Set and cleared by software to select SYSCLK source.
Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
enabled).
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
11: Not allowed                     */

			RCC_CFGR |= (0b10<<0);



/*Bits 7:4 HPRE[3:0]: AHB prescaler
Set and cleared by software to control AHB clock division factor.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2     */


		RCC_CFGR &= ~(0b1111<<4);


/*Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
    */

			RCC_CFGR |= (0b101<<11);

/*Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
0xx: HCLK not divided
100: HCLK divided by 2
  */

			RCC_CFGR |= (0b100<<8);



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
