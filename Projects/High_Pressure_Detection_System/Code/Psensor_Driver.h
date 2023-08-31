/*
 * Psensor_Driver.h
 *
 *  Created on: Aug 29, 2023
 *      Code By: Mohamed Nabil Mohamed
 */

#ifndef PSENSOR_DRIVER_H_
#define PSENSOR_DRIVER_H_

//Defines
#define Psensor_pressure_pull_time 6000

//Includes
#include "state.h"

//State IDs
enum{
	PSensor_busy,
	PSensor_idle
}PSensor_state_id;


//Prototypes
void PressureSensor_init();
STATE_DEFINE(PSensor_busy);
STATE_DEFINE(PSensor_idle);


//State pointer
void (*PSensor_state)();


#endif /* PSENSOR_DRIVER_H_ */
