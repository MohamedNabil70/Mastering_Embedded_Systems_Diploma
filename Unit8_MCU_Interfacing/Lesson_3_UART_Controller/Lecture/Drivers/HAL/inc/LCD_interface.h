/*
 * LCD_interface.h
 *
 * Created: 9/11/2022 11:33:19 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

//-----------------------------
//Includes
//-----------------------------

/*UTILS*/
#include "../../STM32F103C8_Drivers/inc/BIT_MATH.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8_GPIO_driver.h"

//-----------------------------
//Macros Configuration References
//-----------------------------

// MACROS For LCD Bit Mode
#define LCD_4_BIT_MODE	4
#define LCD_8_BIT_MODE	8

// MACROS For LCD Shift Direction
#define LCD_SHIFT_LEFT	0
#define LCD_SHIFT_RIGHT	1

// MACROS For LCD Line Number
#define LCD_LINE_ONE 1
#define LCD_LINE_TWO 2


//Main Functions
void LCD_setPinDirections(void);
void LCD_init(void);
void LCD_sendCmnd(uint8_t cmnd);
void LCD_sendChar(uint8_t data);


//OTHER Functions
void LCD_sendString(char* data);
void LCD_typeString(char* data);  //Send string with typing effect
void LCD_writeNumber(uint32_t number);
void LCD_clear(void);
void LCD_shift(uint8_t shiftDirection);
void LCD_goToSpecificPosition(uint8_t lineNumber,uint8_t position);

/*
void LCD_writeSpecialCharacter(uint8_t* pattern,uint8_t charPosition,uint8_t lineNumber,uint8_t position);
 */



#endif /* LCD_INTERFACE_H_ */
