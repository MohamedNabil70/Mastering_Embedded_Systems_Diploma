/*
 * Alarm_Monitor.h
 *
 *  Created on: Aug 29, 2023
 *     Code By: Mohamed Nabil Mohamed
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

//Defines
#define alarm_duration 20000

//Includes
#include "state.h"

//States IDs
enum{
	Alarm_Monitor_AlarmOn,
	Alarm_Monitor_AlarmOff,
	Alarm_Monitor_waiting
}Alarm_Monitor_state_id;


//Prototypes
STATE_DEFINE(Alarm_Monitor_AlarmOn);
STATE_DEFINE(Alarm_Monitor_AlarmOff);
STATE_DEFINE(Alarm_Monitor_waiting);

//State pointer
void (*Alarm_Monitor_state)();



#endif /* ALARM_MONITOR_H_ */
