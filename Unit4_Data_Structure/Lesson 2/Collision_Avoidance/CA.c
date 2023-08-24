/*
 * CA.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

//includes
#include "state.h"
#include"CA.h"

//global variables
unsigned int CA_distance =0;
unsigned int CA_speed = 0;
unsigned int CA_threshold = DISTANCE_THRESHOLD;

extern void (*CA_state)();

//Functions

void US_set_distance(int distance){

	//transport distance reading from US module
	CA_distance = distance;

	//print status
	printf ("US_sensor ----distance=%d------> CA\n",distance);

	//CHECK Condition
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));


}


STATE_DEFINE(CA_waiting){

	//state id
	CA_state_id = CA_waiting;


	//set motor speed
	CA_speed = 0;
	printf ("CA_Waiting === distance=%d ,Speed=%d\n",CA_distance,CA_speed);
	DC_set_speed(CA_speed);




}

STATE_DEFINE(CA_driving){

	//state id
	CA_state_id = CA_driving;

	//set motor speed
	CA_speed = 30;
	printf ("CA_Driving === distance=%d ,Speed=%d\n",CA_distance,CA_speed);
	DC_set_speed(CA_speed);



}
