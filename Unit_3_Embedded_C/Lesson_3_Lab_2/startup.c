/* 
startup.s ARM-cortex-M3 (an application on STM32)
Learn-in-depth Unit 3 Lesson 3 Lab_2
		~Made by Mohamed Nabil~
*/


#include <stdint.h>

extern unsigned int _stack_top;

extern int main(void);
void Default_Handler();
void Reset_Handler(void);
void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));


 
uint32_t vectors[] __attribute__((section(".vectors")))={
	
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler ,
	(uint32_t) &H_Fault_Handler ,	
	(uint32_t) &MM_Fault_Handler ,	
	(uint32_t) &Bus_Fault ,	
	(uint32_t) &Usage_Fault_Handler ,	
	
	};

extern unsigned int _E_text ;	
extern unsigned int _S_data ;
extern unsigned int _E_data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
          

	
	
void Reset_Handler(){
	
	int i;
	//copy .data section from flash to RAM
	unsigned int Data_Size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_data ;
	
	for(i=0;i<Data_Size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	
	//init .bss section into RAM and set to 0
	unsigned int BSS_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(i=0;i<BSS_Size;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}	

	
	
	//call main function
	main();
}


void Default_Handler(){
	Reset_Handler();	
} 
// void NMI_Handler(){
// Reset_Handler();	
// }

// void H_Fault_Handler(){
// Reset_Handler();	
// }

// void MM_Fault_Handler(){
// Reset_Handler();	
// }

// void Bus_Fault(){
// Reset_Handler();	
// }

// void Usage_Fault_Handler(){
// Reset_Handler();	
// }
