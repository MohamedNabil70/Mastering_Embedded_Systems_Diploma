/*
 * SERVO_interface.h
 *
 * Created: 9/30/2022 10:11:21 PM
 *  Author: Mohamed Nabil
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define SERVO_DRIVING_TIMER_1		1
#define SERVO_DRIVING_TIMER_2		2

/*
drivingTimers:
1- SERVO_DRIVING_TIMER_1
2- SERVO_DRIVING_TIMER_2

DesiredAngle:
-90 --> +90
*/

void SERVO_on(u8 drivingTimer,s8 DesiredAngle); 


#endif /* SERVO_INTERFACE_H_ */