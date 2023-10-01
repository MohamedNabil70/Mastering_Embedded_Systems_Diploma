/*
 * KERNAL_program.c
 *
 * Created: 10/18/2022 10:02:50 AM
 *  Author: Mohamed Nabil 
 */ 


		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "GI_Interface.h"
		
		/* RTOS STACK */
		#include "TMR_interface.h"
		#include "TMR_config.h"
		#include "KERNAL_config.h"
		#include "KERNAL_interface.h"


Task_t TaskArr[RTOS_TASK_NUM];
		

void RTOS_start(void)		
{
	GI_enable();
	TMR_timer0init();
	TMR_timer0SetCompareMatchValue(249);
	TMR_timer0_CTC_setCallBack(&privateSchedular);
	TMR_timer0start();
	
}

void RTOS_createTask(u8 priority,u16 periodisty,void (*pTaskCode)(void))
{
	
	if ((priority<RTOS_TASK_NUM) && (pTaskCode !=NULL) && (TaskArr[priority].pTaskFunc == NULL))
	{
	TaskArr[priority].TaskPeriodisty = periodisty;
	TaskArr[priority].pTaskFunc		 = pTaskCode;
	TaskArr[priority].TaskState		 = RTOS_TASK_RESUMED;

	}else{
		//Do nothing
	}
}


void RTOS_suspendTask(u8 priority)
{
	TaskArr[priority].TaskState = RTOS_TASK_SUSPENDED;
}

void RTOS_resumeTask(u8 priority)
{
	TaskArr[priority].TaskState = RTOS_TASK_RESUMED;
}

void RTOS_deleteTask		(u8 priority)
{
	TaskArr[priority].pTaskFunc = NULL;
}



static void privateSchedular(void)
{
static volatile u16 tickCounter = 0;
 
 ++tickCounter;
 
u8 taskCounter;

for(taskCounter=0;taskCounter<RTOS_TASK_NUM;taskCounter++)
{
	
	if ( (TaskArr[taskCounter].TaskState == RTOS_TASK_RESUMED) && ((tickCounter % (TaskArr[taskCounter].TaskPeriodisty) ) == 0))
	{
		if (TaskArr[taskCounter].pTaskFunc != NULL)
		{
				TaskArr[taskCounter].pTaskFunc();	
		}else
	{
	//Do Nothing	
	}
	
	} 
	else
	{
	//Do Nothing	
	}
	
}
	
}







