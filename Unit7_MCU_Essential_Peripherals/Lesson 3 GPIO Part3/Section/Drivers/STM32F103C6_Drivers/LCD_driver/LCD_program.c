/*
 * LCD_program.c
 *
 * Created: 9/11/2022 11:32:37 AM
 *  Author: Mohamed Nabil
 */ 



/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"


/*MAIN Functions*/

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}





void LCD_setPinDirections(void)
{
	GPIO_PinConfig_t PinCfg;

	/* LCD Data Pins Direction [Modes] */


#if LCD_MODE == LCD_8_BIT_MODE

	//specific pins for LCD_8_BIT_MODE
	
	PinCfg.GPIO_PinNumber = LCD_D0_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D0_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D1_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D1_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D2_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D2_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D3_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D3_PORT, &PinCfg);

#endif

	//common pins between 2 modes 

	PinCfg.GPIO_PinNumber = LCD_D4_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D4_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D5_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D5_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D6_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D6_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_D7_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_D7_PORT, &PinCfg);


	/* LCD Control Pins Direction */
	PinCfg.GPIO_PinNumber = LCD_RS_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_RW_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_E_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

}		

void LCD_init(void)
{
	delay_ms(35);
#if LCD_MODE == LCD_4_BIT_MODE
	//set Rs pin to 0 (command)
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_LOW);
	//set Rw pin to 0 (write)
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW);

	writeHalfPort(0b0010);
	//enable pulse H=>L
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);
	LCD_sendCmnd(0b00101000);
#elif LCD_MODE == LCD_8_BIT_MODE
	LCD_sendCmnd(0b00111000);
#endif
	delay_ms(1);
	//display on,blink on, cursor on
	LCD_sendCmnd(0b00001111);
	delay_ms(1);
	// clear display
	LCD_sendCmnd(0b00000001);
	delay_ms(2);
	//set
	LCD_sendCmnd(0b00000110);

}

void LCD_sendCmnd(uint8_t cmnd)
{
	//set Rs pin to 0 (command)
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_LOW);
	//set Rw pin to 0 (write)
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW);

#if LCD_MODE == LCD_8_BIT_MODE

	MCAL_GPIO_WritePort(LCD_DATA_PORT,cmnd);
	//enable pulse H=>L
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);

#elif LCD_MODE == LCD_4_BIT_MODE

	//write most Seg 4 bits of command
	writeHalfPort(cmnd>>4);
	//enable pulse H=>L
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);
	//write least seg 4 bits command
	writeHalfPort(cmnd);
	//enable pulse H=>L	
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);

#endif
}

void LCD_sendChar(uint8_t data)
{
	//set Rs pin to 1 (data)
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_HIGH);
	//set Rw pin to 0 (write)
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW);

#if LCD_MODE == LCD_8_BIT_MODE

	MCAL_GPIO_WritePort(LCD_DATA_PORT,data);
	//enable pulse H=>L
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);

#elif LCD_MODE == LCD_4_BIT_MODE
	//write most seg 4 bits of data
	writeHalfPort(data>>4);
	//enable pulse H=>L
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);
	//write least seg 4 bits of data
	writeHalfPort(data);
	//enable pulse H=>L	
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_HIGH);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_E_PORT,LCD_E_PIN,GPIO_PIN_LOW);

#endif
}



static void writeHalfPort(uint8_t value)
{
	if(1 == GET_BIT(value,0))
	{
		MCAL_GPIO_WritePin(LCD_D4_PORT,LCD_D4_PIN,GPIO_PIN_HIGH);
	}else{
		MCAL_GPIO_WritePin(LCD_D4_PORT,LCD_D4_PIN,GPIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,1))
	{
		MCAL_GPIO_WritePin(LCD_D5_PORT,LCD_D5_PIN,GPIO_PIN_HIGH);
	}else{
		MCAL_GPIO_WritePin(LCD_D5_PORT,LCD_D5_PIN,GPIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,2))
	{
		MCAL_GPIO_WritePin(LCD_D6_PORT,LCD_D6_PIN,GPIO_PIN_HIGH);
	}else{
		MCAL_GPIO_WritePin(LCD_D6_PORT,LCD_D6_PIN,GPIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,3))
	{
		MCAL_GPIO_WritePin(LCD_D7_PORT,LCD_D7_PIN,GPIO_PIN_HIGH);
	}else{
		MCAL_GPIO_WritePin(LCD_D7_PORT,LCD_D7_PIN,GPIO_PIN_LOW);
	}

}


/*OTHER Functions*/

void LCD_sendString(char* data)
{
	if (data != NULL)
	{
		uint8_t count=0;
		while (data[count] != '\0')
		{
			LCD_sendChar(data[count]);
			count++;
		}

	}

}

void LCD_typeString(char* data)
{
	if (data != NULL)
	{
		uint8_t count=0;
		while (data[count] != '\0')
		{
			LCD_sendChar(data[count]);
			delay_ms(65);
			count++;
		}

	}

}


void LCD_writeNumber(uint32_t number)  //Written by Eng Kareem
{
	uint32_t Local_reversed = 1;
	if (number == 0)
	{
		LCD_sendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}

		do 
		{
			LCD_sendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	} 
}

void LCD_clear(void)
{
	// Clear display
	LCD_sendCmnd(0b00000001);
	delay_ms(2);
}

void LCD_shift(uint8_t shiftDirection)
{
	if (shiftDirection == LCD_SHIFT_LEFT)
	{
		LCD_sendCmnd(0b00011000);
		delay_ms(10);
	}else if(shiftDirection == LCD_SHIFT_RIGHT){

		LCD_sendCmnd(0b00011100);
		delay_ms(10);

	}
}

void LCD_goToSpecificPosition(uint8_t lineNumber,uint8_t position)
{
	if(lineNumber == LCD_LINE_ONE)
	{
		if (position<16)
		{
			LCD_sendCmnd(0x80 + position);
		}

	}else if (lineNumber == LCD_LINE_TWO){
		if (position<16)
		{
			LCD_sendCmnd(0xC0 + position);
		}
	}
}


/*
void LCD_writeSpecialCharacter(uint8_t* pattern,uint8_t charPosition,uint8_t lineNumber,uint8_t position)
{

}
 */

