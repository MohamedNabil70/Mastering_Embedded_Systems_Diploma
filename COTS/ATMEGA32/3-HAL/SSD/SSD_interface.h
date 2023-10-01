/*
 * SSD_interface.h
 *
 * Created: 9/18/2022 12:42:42 PM
 *  Author: Mohamed Nabil
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* Main Functions*/
void SSD_on(void);
void SSD_off(void);
void SSD_displayDigit(u8 digit);
static void writeHalfPort(u8 value);

/* Additional Functions*/

//SSD Display 2 Digit Number Functions
void SSD_displayNumber(u8 number); // this function should be placed in while (1)
void SSD_displayNumberFor1Second(u8 number); //Has it's own counter
void SSD_displayNumber_forSpicificTime(u8 number,u8 seconds);//Has it's own counter

//Counter Functions
void SSD_countUp(u8 seconds);
void SSD_countDown(u8 seconds);

//Digit [on/off] Functions
void SSD_on_right(void);
void SSD_on_left(void);
void SSD_off_right(void);
void SSD_off_left(void);



#endif /* SSD_INTERFACE_H_ */