/*
 * KPD_config.h
 *
 * Created: 9/13/2022 10:06:45 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

//Rows Config [Input]
#define KPD_ROWS_NUM	4
#define KPD_ROWS_PORT	GPIOB

#define KPD_ROW0_PIN	GPIO_PIN_0
#define KPD_ROW1_PIN	GPIO_PIN_1
#define KPD_ROW2_PIN	GPIO_PIN_3
#define KPD_ROW3_PIN	GPIO_PIN_4


//Columns Config [Output]
#define KPD_COLS_NUM	4
#define KPD_COLS_PORT	GPIOB

#define KPD_COL0_PIN	GPIO_PIN_5
#define KPD_COL1_PIN	GPIO_PIN_6
#define KPD_COL2_PIN	GPIO_PIN_7
#define KPD_COL3_PIN	GPIO_PIN_8


//Keys Config
//@ref KPD_KEYS
#define KPD_KEYS  {'7','8','9','/','4','5','6','*','1','2','3','-','!','0','=','+'}




#endif /* KPD_CONFIG_H_ */
