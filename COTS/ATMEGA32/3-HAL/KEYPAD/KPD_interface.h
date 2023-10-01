/*
 * KPD_interface.h
 *
 * Created: 9/13/2022 10:06:23 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


#define KPD_NOT_PRESSED 0xff  //any initial value for (*returnedValue)

void KPD_getValue(u8* returnedValue);



#endif /* KPD_INTERFACE_H_ */