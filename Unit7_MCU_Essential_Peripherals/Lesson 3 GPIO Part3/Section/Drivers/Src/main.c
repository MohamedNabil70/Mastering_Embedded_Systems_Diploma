/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit7_Lesson3_Section
 *
 *	This application is used to test my LCD and KEYPAD Drivers on STM32F103C6 MCU
 *	LQFP48 Package mounted on BluePill kit
 *
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

#include "LCD_interface.h"
#include "LCD_config.h"
#include "KPD_config.h"
#include "KPD_interface.h"

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10


extern void delay_ms(uint32_t time);

void clock_init(void){

	//Enable clock to port A
	RCC_GPIOA_CLK_EN();
	//Enable clock to port B
	RCC_GPIOB_CLK_EN();

}


void GPIO_init(void){

	GPIO_PinConfig_t PinCfg;

	// 7 Segment Pins init:
	/*Init GPIOB*/

	//PB9 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB10 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB11 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB12 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB13 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB14 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PB15 Push-pull Output [Max speed 10MHz]
	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}



int main(void)
{

	//Initializations
	clock_init();
	GPIO_init();
	LCD_setPinDirections();
	LCD_init();

	unsigned char kpdkey,line_guard=0;

	LCD_typeString("Hey");
	delay_ms(250);
	LCD_clear();

	unsigned char LCD_SSEG_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char SSEG_DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};

	for (unsigned char i = 0; i < 11; i++) {
		LCD_sendChar(LCD_SSEG_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, SSEG_DISPLAY[i] << 9); /* write data on to the 7-Segment port */
		delay_ms(200);
		/* wait for 1 second */
	}
		LCD_clear();



		KPD_init();
		LCD_typeString("Keypad is ready...");
		delay_ms(250);
		LCD_clear();

	while(1)
	{
		KPD_getValue( &kpdkey );

			if(kpdkey != KPD_NOT_PRESSED)
			{

					if (line_guard == 16)
					{
						LCD_goToSpecificPosition(LCD_LINE_TWO,0);
					}
					else if(line_guard > 32)
					{
						line_guard=0;
						LCD_clear();
					}

					if (kpdkey == '!')
					{
						LCD_clear();
					}
				else
				LCD_sendChar(kpdkey);

				line_guard++;

			}

			delay_ms(30);

	}

}
