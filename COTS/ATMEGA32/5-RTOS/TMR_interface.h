/*
 * TMR_interface.h
 *
 * Created: 9/25/2022 5:56:21 AM
 *  Author: Mohamed Nabil 
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_




//TIMER 0 PRESCALER MODE MACROS [CS0x pins]

#define TMR_TMR0_PRESCALER_1	  	    1	
#define TMR_TMR0_PRESCALER_8		    2
#define TMR_TMR0_PRESCALER_64	  	    3 
#define TMR_TMR0_PRESCALER_256		    4
#define TMR_TMR0_PRESCALER_1024		    5
#define TMR_TMR0_PRESCALER_EXT_FE	    6
#define TMR_TMR0_PRESCALER_EXT_RE		7

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//		
		/*TIMER 0*/
		
void TMR_timer0init(void);
void TMR_timer0start(void);
void TMR_timer0stop(void);
// TMR0_NORMAL_MODE 
// TMR0_CTC_MODE
void TMR_timer0SetCompareMatchValue (u8 OCR0_Value);
void TMR_timer0_CTC_setCallBack		(void(*ptr)(void));


#endif /* TMR_INTERFACE_H_ */