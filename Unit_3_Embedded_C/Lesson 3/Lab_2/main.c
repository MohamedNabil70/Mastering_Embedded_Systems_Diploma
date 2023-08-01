
/* 
 *******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil
 * @brief          : Main program body
 ******************************************************************************

 */

#include <stdint.h>

typedef volatile unsigned int vuint32_t;


//REGESTERS ADDRESSES
#define RCC_BASE   0X40021000
#define GPIOA_BASE 0X40010800

#define RCC_APB2ENR   *(volatile uint32_t *) (RCC_BASE + 0X18)
#define GPIOA_CRH     *(volatile uint32_t *) (GPIOA_BASE + 0X04)
#define GPIOA_ODR     *(volatile uint32_t *) (GPIOA_BASE + 0X0C)

typedef union{
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13 ;
		vuint32_t pin13:1 ;
	}pins;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*) (GPIOA_BASE + 0X0C);
unsigned char g_char[3]={1,2,3};
unsigned const char const_char[3]={1,2,3};
//unsigned char bss_char[3];

int main(void)
{

	RCC_APB2ENR |= (1<<2) ;
	GPIOA_CRH &= 0xff0fffff ;
	GPIOA_CRH |= 0x00200000 ;

int i=0;
	while(1){

		R_ODR->pins.pin13= 1; //set Bit 13 (HIGH)
		for( i =0 ;i < 7000; i++); //arbitrary Delay

		R_ODR->pins.pin13= 0; //reset Bit 13 (LOW)
		for( i =0 ;i < 7000; i++);  //arbitrary Delay


	}


	return 0;
}


extern void NMI_Handler(){
Reset_Handler();	
}

extern void H_Fault_Handler(){
Reset_Handler();	
}