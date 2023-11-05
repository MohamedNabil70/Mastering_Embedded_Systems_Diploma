/*
 * LCD_config.h
 *
 * Created: 9/11/2022 11:33:42 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


						/*Macros For Control Pins Configuration*/

#define LCD_CONTROL_PORT	 GPIOA

//Macros For Rs Pin
#define LCD_RS_PORT			 GPIOA
#define LCD_RS_PIN			 GPIO_PIN_8

//Macros For Rw Pin
#define LCD_RW_PORT			 GPIOA
#define LCD_RW_PIN			 GPIO_PIN_9

//Macros For Enable Pin
#define LCD_E_PORT			 GPIOA
#define LCD_E_PIN			 GPIO_PIN_10

						/*Macros For DATA Pins Configuration*/
/*
Options For LCD Mode:
 LCD_8_BIT_MODE
 LCD_4_BIT_MODE     */
 
#define LCD_MODE	 LCD_4_BIT_MODE

/*Macros For 8 bit mode Configuration only ( [first 4 bits] 0>>3)*/

//FULL PORT CONTROL
#define LCD_DATA_PORT		GPIOA


#define LCD_D0_PORT		GPIOA
#define LCD_D0_PIN		GPIO_PIN_0

#define LCD_D1_PORT		GPIOA
#define LCD_D1_PIN		GPIO_PIN_1

#define LCD_D2_PORT		GPIOA
#define LCD_D2_PIN		GPIO_PIN_2

#define LCD_D3_PORT		GPIOA
#define LCD_D3_PIN		GPIO_PIN_3


/*Macros For 4 or 8 bit mode Configuration*/

#define LCD_D4_PORT		GPIOA
#define LCD_D4_PIN		GPIO_PIN_4

#define LCD_D5_PORT		GPIOA
#define LCD_D5_PIN		GPIO_PIN_5

#define LCD_D6_PORT		GPIOA
#define LCD_D6_PIN		GPIO_PIN_6

#define LCD_D7_PORT		GPIOA
#define LCD_D7_PIN		GPIO_PIN_7

#endif /* LCD_CONFIG_H_ */
