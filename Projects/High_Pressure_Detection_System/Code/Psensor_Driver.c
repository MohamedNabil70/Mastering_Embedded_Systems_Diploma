/*
 * Psensor_Driver.c
 *
 *  Created on: Aug 29, 2023
 *      Code By: Mohamed Nabil Mohamed
 */

//Includes
#include "Psensor_Driver.h"
#include "driver.h"




//Module Variables
int Psensor_pressureVal = 0;

extern void (*PSensor_state)();


//Functions

void PressureSensor_init(){

	//Set first state
	PSensor_state = STATE(PSensor_busy);

}

STATE_DEFINE(PSensor_busy){

	//Read pressure value from pressure sensor
	Psensor_pressureVal = getPressureVal();

	//Send signal (PressureSensor_Driver ---> Main_Algorithm)
	SetPressureValue(Psensor_pressureVal);

	//Update state
	PSensor_state = STATE(PSensor_idle);

}

STATE_DEFINE(PSensor_idle){

	//Delay between readings
	Delay(Psensor_pressure_pull_time);

	//Set first state
	PSensor_state = STATE(PSensor_busy);

}


