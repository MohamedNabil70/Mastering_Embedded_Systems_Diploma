/*
 * GI_program.c
 *
 * Created: 9/18/2022 9:49:14 AM
 *  Author: Mohamed Nabil
 */ 


	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "GI_Interface.h"
	
	void GI_enable(void)
	{
	SET_BIT(SREG,7); //Enable global interrupt
	}
	
	void GI_disable(void)
	{
		CLR_BIT(SREG,7); //Disable global interrupt
	}