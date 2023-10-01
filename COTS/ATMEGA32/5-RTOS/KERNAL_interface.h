/*
 * KERNAL_interface.h
 *
 * Created: 10/18/2022 10:03:03 AM
 *  Author: Mohamed Nabil 
 */ 


#ifndef KERNAL_INTERFACE_H_
#define KERNAL_INTERFACE_H_

#define RTOS_TASK_SUSPENDED		0
#define RTOS_TASK_RESUMED		1


typedef struct{
	
	void (*pTaskFunc)(void);
	u16 TaskPeriodisty;
	u8 TaskState;
	
	}Task_t;

//periodisty: «·“„‰ «··«“„ · ﬂ—«—  ‰›Ì– «· «”ﬂ

void RTOS_start				(void);
void RTOS_createTask		(u8 priority,u16 periodisty,void (*pTaskCode)(void));
void RTOS_suspendTask		(u8 priority);
void RTOS_resumeTask		(u8 priority);
void RTOS_deleteTask		(u8 priority);

static void privateSchedular(void);




#endif /* KERNAL_INTERFACE_H_ */