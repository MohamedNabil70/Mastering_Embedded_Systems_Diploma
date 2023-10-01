/*
 * KPD_interface.h
 *
 * Created: 9/13/2022 10:06:23 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

//-----------------------------
//Includes
//-----------------------------

/* MCAL */
#include "STM32F103x8.h"
#include "STM32F103x8_GPIO_driver.h"

//-----------------------------
//Macros Configuration References
//-----------------------------

#define KPD_NOT_PRESSED 0xff  //any initial value for (*returnedValue)

/*
 * ===============================================
 * APIs Supported by "HAL KPD DRIVER"
 * ===============================================
 */

void KPD_init(void);
void KPD_getValue(uint8_t* returnedValue);



#endif /* KPD_INTERFACE_H_ */
