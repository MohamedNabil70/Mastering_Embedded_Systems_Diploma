/*
 * US_sensor.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */


//includes
#include <stdlib.h>
#include <time.h>
#include "state.h"
#include"US_sensor.h"

//global variables
unsigned int  US_distance=0;

extern void (*US_state)();

//Functions

int generate_random(int min, int max){
	//generate random number between min & max

    // Generate a random number between min and max

    int randomNumber = min+rand()%(max-min+1);

    return randomNumber;

}


void US_init(){

	/*US_sensor driver initialization code*/

	printf("US_init\n");

}

STATE_DEFINE(US_busy){

	//state id
	US_state_id = US_busy;

	//read distance using sensor (we use random value generator to test our code)
	US_distance = generate_random(45,55);
	printf("US_busy === distance=%u\n",US_distance);

	//send distance
	US_set_distance(US_distance);

	US_state = STATE(US_busy);


}



