/*
 * Main_Algorithm.h
 *
 *  Created on: Aug 29, 2023
 *      Code By: Mohamed Nabil Mohamed
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

//Includes
#include "state.h"

//Defines
#define Pthreshold 20  //select Pressure threshold value in bars

//State IDs
enum{
	High_Pressure_Check
}Main_Algorithm_state_id;


//Prototypes
STATE_DEFINE(High_Pressure_Check);


//State pointer
void (*Main_Algorithm_state)();


#endif /* MAIN_ALGORITHM_H_ */
