/*
 * state.h
 *
 *  Created on: Aug 29, 2023
 *      Code By: Mohamed Nabil Mohamed
 */

#ifndef STATE_H_
#define STATE_H_


//includes
#include<stdint.h>


//Defines
#define STATE_DEFINE(_state_func_) void stateFunction_##_state_func_()
#define STATE(_state_func_) stateFunction_##_state_func_


/*------state connections------*/

//PressureSensor_Driver ---> Main_Algorithm
void SetPressureValue(int pressureVal);

//Main_Algorithm ---> Alarm_Monitor
void HighPressureDetected();

//Alarm_Monitor ---> Alarm_Actuator_Driver
void Set_Alarm_Actuator();
void Stop_Alarm_Actuator();


#endif /* STATE_H_ */
