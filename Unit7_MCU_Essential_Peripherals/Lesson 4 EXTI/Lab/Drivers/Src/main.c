/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit7_Lesson4
 *
 *
 ******************************************************************************
 *		This application is used to test my EXTI driver for STM32F103x8 Based on LQFP48 Package.
 *		it is required to enable EXTI and map it for GPIO port B Pin 9 to detect a Falling edge change
 *		and accordingly display a message on LCD Using LCD generic driver
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//-----------------------------
//Includes
//-----------------------------

//UTILS
#include "STM32F103x8.h"

//MCALL
#include "STM32F103x8_GPIO_driver.h"
#include "STM32F103x8_EXTI_driver.h"

//HAL
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KPD_config.h"
#include "KPD_interface.h"


uint32_t IRQ_Flag ;

extern void delay_ms(uint32_t time);

void clock_init(void){

	//Enable clock to AFIO
	RCC_AFIO_CLK_EN();
	//Enable clock to port A
	RCC_GPIOA_CLK_EN();
	//Enable clock to port B
	RCC_GPIOB_CLK_EN();


}

void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	LCD_typeString("IRQ EXTI9 Has");
	LCD_goToSpecificPosition(LCD_LINE_TWO, 0);
	LCD_typeString("Happened --|__");

	delay_ms(250);
}


int main(void)
{
	//Initializations
	clock_init();
	LCD_setPinDirections();
	LCD_init();


	EXTI_PinConfig_t PINCONFIG;

	PINCONFIG.EXTI_Pin = EXTI9PB9;
	PINCONFIG.IRQ_EN = EXTI_IRQ_ENABLE;
	PINCONFIG.P_IRQ_CallBack = EXTI9_CallBack;
	PINCONFIG.Trigger_Case = EXTI_Trigger_FALLING;

	MCAL_EXTI_GPIO_Init(&PINCONFIG);

	IRQ_Flag = 1;

	while(1)
	{

		if(IRQ_Flag == 1)
		{
			LCD_clear();
			IRQ_Flag = 0;
		}

	}

}
