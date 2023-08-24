/*
 * DC_motor.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

//includes
#include "state.h"
#include"DC_motor.h"

//global variables
unsigned int DC_speed = 0;

extern void(*DC_state)();

//functions

void DC_set_speed(int speed){

	DC_speed = speed;

	//set motor speed to 30
	/*code*/

	//print status
	printf ("CA ----speed=%d------> DC_motor\n",speed);

	//set next state
	DC_state = STATE(DC_busy);

}


void DC_init(){
	//DC_motor_initialization

	//print message
	printf ("DC_motor_init\n");
}


STATE_DEFINE(DC_idle){

	//state id
	DC_state_id = DC_idle;

	//state action


	printf ("DC_idle state === speed=%d\n" , DC_speed);

}


STATE_DEFINE(DC_busy){

	//state id
	DC_state_id = DC_busy;

	printf ("DC_busy state === speed=%d\n" , DC_speed);

	//set next state
	DC_state = STATE(DC_idle);

}
