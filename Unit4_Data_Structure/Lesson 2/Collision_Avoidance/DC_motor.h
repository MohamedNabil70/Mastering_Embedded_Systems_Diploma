/*
 * DC_motor.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

#ifndef DC_motor_H_
#define DC_motor_H_



#endif /* DC_motor_H_ */


//includes
#include "state.h"

//state id's
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//prototypes
void DC_init(       );
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

//state pointers
void (*DC_state)();
