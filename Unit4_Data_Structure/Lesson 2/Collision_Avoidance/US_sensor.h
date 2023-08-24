/*
 * US_sensor.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

#ifndef US_sensor_H_
#define US_sensor_H_

//includes
#include "state.h"

//state ids
enum{
	US_busy
}US_state_id;


//prototypes

void US_init();
STATE_DEFINE(US_busy);

//state pointers
void (*US_state)();


#endif /* US_sensor_H_ */
