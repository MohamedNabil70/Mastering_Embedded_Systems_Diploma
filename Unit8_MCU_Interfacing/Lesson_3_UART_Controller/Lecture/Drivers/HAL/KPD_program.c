/*
 * KPD_program.c
 *
 * Created: 9/13/2022 10:06:03 AM
 *  Author: Mohamed Nabil
 */ 


/* HAL */
#include "../inc/KPD_config.h"
#include "../inc/KPD_interface.h"



/**===============================================================================================
 * @FName			- KPD_init
 * @Brief 			- Used to set pin modes and initialize KeyPad
 * @Parameter [in] 	-NONE
 *
 * @Return Value	- NONE
 * Note				- NONE
 */
void KPD_init(void)
{
	GPIO_PinConfig_t PinCfg;


	//Rows Pins Config [Input with pull-up resistance]

		PinCfg.GPIO_PinNumber = KPD_ROW0_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
		MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = KPD_ROW1_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
		MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = KPD_ROW2_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
		MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = KPD_ROW3_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
		MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

		//Columns Pins Config [General purpose output push-pull]
		//Push-pull Output [Max speed 10MHz]

			PinCfg.GPIO_PinNumber = KPD_COL0_PIN;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
			MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

			PinCfg.GPIO_PinNumber = KPD_COL1_PIN;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
			MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

			PinCfg.GPIO_PinNumber = KPD_COL2_PIN;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
			MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

			PinCfg.GPIO_PinNumber = KPD_COL3_PIN;
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
			MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);
}

/**===============================================================================================
 * @FName			- KPD_getValue
 * @Brief 			- Used to get the value of any button pressed in keypad
 * @Parameter [in] 	-returnedValue: a pointer takes the address of the variable that you want to get the keypad
 * 					 				keypad button reading on it [the returned value is the ascii code of the button
 * 					 				according to @ref KPD_KEYS in the KPD_config.h file]
 * @Return Value	- NONE
 * Note				- This function is designed to be called inside an infinite loop to work as expected
 */
void KPD_getValue(uint8_t* returnedValue)
{
	*returnedValue = KPD_NOT_PRESSED;  //if returnedValue remains KPD_NOT_PRESSED then no change is done

	uint8_t KPD_Chars[KPD_ROWS_NUM][KPD_COLS_NUM] = KPD_KEYS;
	uint16_t colPins[KPD_COLS_NUM] = {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	uint16_t rowPins[KPD_ROWS_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	if (returnedValue!=NULL)
	{
		uint8_t row,column, c;
		uint8_t pinValue;
		uint8_t pinFlag=0;

		for (column=0 ; column < KPD_COLS_NUM ; column++)
		{

			//Deactivate all columns
			for(c = 0; c < KPD_COLS_NUM ; c++){

				MCAL_GPIO_WritePin(KPD_COLS_PORT,colPins[c],GPIO_PIN_LOW);
			}

			//Activate current column
			MCAL_GPIO_WritePin(KPD_COLS_PORT,colPins[column],GPIO_PIN_HIGH);

			for ( row = 0 ; row < KPD_ROWS_NUM ; row++)
			{
				//Read current row
				pinValue = MCAL_GPIO_ReadPin(KPD_ROWS_PORT,rowPins[row]);
				if (pinValue == 1)
				{
					//Read current row and column ascii if pressed
					*returnedValue = KPD_Chars[row][column];
					//as long as you hold the key the *while* will stop the algorithm from repeating
					while (pinValue == 1)
					{
						pinValue = MCAL_GPIO_ReadPin(KPD_ROWS_PORT,rowPins[row]);
					}
					pinFlag=1;
					break;
				}
			}
			//Deactivate current column
			MCAL_GPIO_WritePin(KPD_COLS_PORT,colPins[column],GPIO_PIN_LOW);

			if (pinFlag == 1)
			{
				break;
			}
		}
	}

}
