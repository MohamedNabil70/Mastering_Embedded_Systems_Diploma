/*
 * main.c
 *
 *  Created on: Aug 29, 2023
 *      Code By: Mohamed Nabil Mohamed
 */

/*----- INCLUDES -----*/
#include <stdint.h>

#include "Psensor_Driver.h"
#include "Main_Algorithm.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator_Driver.h"

#include "driver.h"

void setup(){

//All initializations

	GPIO_INITIALIZATION();

	PressureSensor_init();
	Alarm_Actuator_init();

	//Initialize states
	Alarm_Monitor_state = STATE(Alarm_Monitor_AlarmOff);
	Main_Algorithm_state = STATE(High_Pressure_Check);

}


int main (){

	 setup();

	 //SUPER LOOP
	while (1)
	{

		PSensor_state();
		Main_Algorithm_state();

		//for algorithm confirmation
		Alarm_Monitor_state();
		Alarm_Actuator_state();
		Alarm_Monitor_state();
		Alarm_Actuator_state();
	}

}


