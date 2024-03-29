/*
 * Alarm_Actuator_Driver.h
 *
 *  Created on: Aug 29, 2023
 *     Code By: Mohamed Nabil Mohamed
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

//Defines
#define ON 0       //according to given project connection (Active low led)
#define OFF 1

//Includes
#include "state.h"

//State IDs
enum{
	Alarm_Actuator_off,
	Alarm_Actuator_on
}Alarm_Actuator_state_id;


//Prototypes
void Alarm_Actuator_init();
STATE_DEFINE(Alarm_Actuator_on);
STATE_DEFINE(Alarm_Actuator_off);


//State pointer
void (*Alarm_Actuator_state)();



#endif /* ALARM_ACTUATOR_DRIVER_H_ */
