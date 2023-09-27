/*
 * KPD_config.h
 *
 * Created: 9/13/2022 10:06:45 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_



//Columns Config [Output]
#define KPD_COLS_NUM	4
#define KPD_COLS_PORT	DIO_PORTD

#define KPD_COL0_PIN	DIO_PIN4 
#define KPD_COL1_PIN	DIO_PIN5
#define KPD_COL2_PIN	DIO_PIN6
#define KPD_COL3_PIN	DIO_PIN7

//Rows Config [Input]
#define KPD_ROWS_NUM	4
#define KPD_ROWS_PORT	DIO_PORTD

#define KPD_ROW0_PIN	DIO_PIN0
#define KPD_ROW1_PIN	DIO_PIN1
#define KPD_ROW2_PIN	DIO_PIN2
#define KPD_ROW3_PIN	DIO_PIN3


//Keys Config
#define KPD_KEYS  {'7','8','9','/' \
				  ,'4','5','6','*' \
				  ,'1','2','3','-' \
				  ,'!','0','=','+'}




#endif /* KPD_CONFIG_H_ */