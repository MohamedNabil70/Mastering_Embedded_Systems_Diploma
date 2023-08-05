/* 
 *******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil
 * @brief          : Main program body
 ******************************************************************************

 */

#include <stdint.h>
typedef volatile unsigned long vuint32_t;


#define SYSCTL_BASE 0X400FE000
#define GPIOF_BASE  0X40025000

#define SYSCTL_RCGC2_R *(volatile unsigned long*)(SYSCTL_BASE + 0X108)
#define GPIO_PORTF_DIR_R *(volatile unsigned long*)(GPIOF_BASE + 0X400)
#define GPIO_PORTF_DEN_R *(volatile unsigned long*)(GPIOF_BASE + 0X51C)

typedef union {
	vuint32_t all_fields;
	struct {
	vuint32_t reserved :3;
	vuint32_t pin3 : 1;
		
	}pins;
	
}GPIO_PORTF_DATA_R_t;

volatile GPIO_PORTF_DATA_R_t* GPIO_PORTF_DATA_R = (volatile GPIO_PORTF_DATA_R_t*)(GPIOF_BASE + 0X3FC);


void main(){
	vuint32_t i;

SYSCTL_RCGC2_R = 0x00000020 ;
//now we add delay to assure GPIO running
for(i=0;i<300;i++);

GPIO_PORTF_DIR_R |= (1<<3);  //Dircetion is output for pin 3 in port F 
GPIO_PORTF_DEN_R |= (1<<3);  


while(1)
{
	GPIO_PORTF_DATA_R->pins.pin3 =1;
	for(i=0;i<25000;i++);
	
	GPIO_PORTF_DATA_R->pins.pin3 =0;
	for(i=0;i<25000;i++);	
}
	
}






