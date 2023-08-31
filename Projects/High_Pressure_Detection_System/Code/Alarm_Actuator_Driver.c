/*
 * Alarm_Actuator_Driver.c
 *
 *  Created on: Aug 29, 2023
 *     Code By: Mohamed Nabil Mohamed
 */

//Includes
#include "Alarm_Actuator_Driver.h"
#include "driver.h"

//Module Variables
extern void (*Alarm_Actuator_state)();

//Functions

void Alarm_Actuator_init(){

	//Set first state
	Alarm_Actuator_state = STATE(Alarm_Actuator_off);
}

/* Alarm_Monitor ---> Alarm_Actuator_Driver */
void Set_Alarm_Actuator(){

	//Set equivalent state
	Alarm_Actuator_state = STATE(Alarm_Actuator_on);
}

void Stop_Alarm_Actuator(){
	//Set equivalent state
	Alarm_Actuator_state = STATE(Alarm_Actuator_off);
}


STATE_DEFINE(Alarm_Actuator_off){
	Set_Alarm_actuator(OFF);
}

STATE_DEFINE(Alarm_Actuator_on){
	Set_Alarm_actuator(ON);
}
