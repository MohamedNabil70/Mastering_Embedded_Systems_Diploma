/*
 * SPI_program.c
 *
 * Created: 10/4/2022 1:26:38 PM
 *  Author: Mohamed Nabil
 */ 


		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "SPI_interface.h"



void SPI_initMaster(void)
{

//Select Data order LSB transmitted first
SET_BIT(SPI->SPCR,5);

//Select Master Mode
SET_BIT(SPI->SPCR,4);

//Select CLK Polarity Falling=>Rising , Select CLK Phase setup => Sample
SET_BIT(SPI->SPCR,3);
SET_BIT(SPI->SPCR,2);

//Select Prescaler factor = 1/16 of main Freq
SET_BIT(SPI->SPCR,0);
CLR_BIT(SPI->SPCR,1);
CLR_BIT(SPI->SPSR,0);


//Enable SPI
SET_BIT(SPI->SPCR,6);
}

void SPI_initSlave(void)
{
//Select Data order LSB transmitted first
SET_BIT(SPI->SPCR,5);

//Select Slave Mode
CLR_BIT(SPI->SPCR,4);

//Select CLK Polarity Falling=>Rising , Select CLK Phase setup => Sample
SET_BIT(SPI->SPCR,3);
SET_BIT(SPI->SPCR,2);



//Enable SPI
SET_BIT(SPI->SPCR,6);	
}

void SPI_masterTrancieve(u8 TxData,u8* RxData)
{
if (RxData != NULL)
{
	
 SPI->SPDR = TxData;	
while(GET_BIT(SPI->SPSR,7) == 0);
*RxData = SPI->SPDR;
}
}


void SPI_slaveTrancieve(u8 TxData,u8* RxData)
{
	if (RxData != NULL)
	{
		while(GET_BIT(SPI->SPSR,7) == 0);
		*RxData = SPI->SPDR;
		SPI->SPDR = TxData;
		
	}
}