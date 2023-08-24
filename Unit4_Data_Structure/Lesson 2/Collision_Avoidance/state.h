/*
 * state.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

#ifndef state_H_
#define state_H_

//includes
#include <stdio.h>
#include <stdlib.h>

//state define
#define STATE_DEFINE(_stateFunc_) void stateFunc_##_stateFunc_()
#define STATE(_stateFunc_)  stateFunc_##_stateFunc_


//state connections
void US_set_distance(int distance);
void DC_set_speed(int speed);






#endif /* state_H_ */
