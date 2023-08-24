/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed Nabil
 */

//includes
#include "state.h"
#include"US_sensor.h"
#include"CA.h"
#include"DC_motor.h"

void setup(){

	//Initializations
	void DC_init();
	void US_init();


	//Initialize states
	US_state = STATE(US_busy);
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_idle);

}


int main(){

	volatile unsigned long long i;

	//To solve input/output buffer bug in eclipse
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	setup();

	while(1){

		US_state();
		CA_state();
		DC_state();

		printf("\n-------------------\n");
		//arbitrary delay
		for(i=0;i<400000;i++);

	}

	return 0;
}


//To solve input/output buffer bug in eclipse

