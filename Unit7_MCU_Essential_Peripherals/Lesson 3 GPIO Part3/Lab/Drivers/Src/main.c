/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit7_Lesson3_Lab1
 *
 *
 *   It is required to use The GPIO Driver in STM32F103C8T6 BluePill Board to
 *   Read Data From External Push Buttons and Turn on LEDs corresponding to (Pressing)
 ******************************************************************************

 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//Learn-in-depth
//supervision ENG: Keroles Shenouda
//Mastering_Embedded System online diploma

#include "STM32F103x6.h"
#include "STM32F103C6_GPIO_driver.h"


void clock_init(void){

	//Enable clock to port A
	RCC_GPIOA_CLK_EN();
	//Enable clock to port B
	RCC_GPIOB_CLK_EN();

}


void GPIO_init(void){

	GPIO_PinConfig_t PinCnfg;

	/*Init GPIOA*/


	//PA1 Floating Input
	PinCnfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCnfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);
	//PA13 Floating Input
	PinCnfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCnfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCnfg);

	/*Init GPIOB*/

	//PB1 Push-pull Output [Max speed 10MHz]
	PinCnfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCnfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);
	//PB13 Push-pull Output [Max speed 10MHz]
	PinCnfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCnfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCnfg);

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


		//Check if PA1 is pressed (external Pull up)
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== 0){ //Single pressed

			//Turn on led on PB1
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			//Trap processor until button not pressed
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)== 0);
		}

		//Check if PA13 is pressed (external Pull down)
			if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)){ //Multi press
				//Turn on led on PB13
				MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
			}

		delay(800);

	}

}
