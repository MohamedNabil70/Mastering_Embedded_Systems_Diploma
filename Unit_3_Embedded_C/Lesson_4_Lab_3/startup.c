/* 
startup.s ARM-cortex-M3 (an application on STM32)
Learn-in-depth Unit 3 Lesson 3 Lab_2
		~Made by Mohamed Nabil~
*/


#include <stdint.h>


extern int main(void);
void Default_Handler();
void Reset_Handler(void);
void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));


static unsigned long stack_top[256]; //create uninitialized array of 256 int to book 1024 Byte licated by .bss


void(*const g_p_fn_vectors[])()__attribute__((section(".vectors"))) = {
	(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	&Reset_Handler,
	&NMI_Handler ,
	&H_Fault_Handler ,	
	&MM_Fault_Handler ,	
	&Bus_Fault ,	
	&Usage_Fault_Handler ,
	
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
