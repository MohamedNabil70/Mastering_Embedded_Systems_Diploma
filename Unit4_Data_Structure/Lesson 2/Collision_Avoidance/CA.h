/*
 * CA.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

#ifndef CA_H_
#define CA_H_


//configurable Data
#define DISTANCE_THRESHOLD 50

//includes
#include "state.h"

//state id's
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//prototypes
STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

//state pointers
void (*CA_state)();


#endif /* CA_H_ */
