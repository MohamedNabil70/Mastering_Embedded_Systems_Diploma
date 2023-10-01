/*
 * TWI_program.c
 *
 * Created: 10/6/2022 12:29:48 PM
 *  Author: Mohamed Nabil
 */ 

		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "TWI_interface.h"
		
/*IMPORTANT NOTE!
in TWI in AVR the register TWCR control in any
function must follow each other without any
other register control in between
[To Avoid Unexpected Behavior]
*/

		/*MAIN Functions*/

void TWI_initMaster(void)
{
//set Clk freq =400KHz [Max clk]
CLR_BIT(TWSR,0);
CLR_BIT(TWSR,1);
TWBR = 12;

//Enable ACKnowledge
SET_BIT(TWCR,6);

//Enable TWI
SET_BIT(TWCR,2);
}


void TWI_initSlave(u8 slaveAdd)
{
	//Set Slave Address
	if ((slaveAdd<128) && (slaveAdd>0))
	{
	TWAR = (slaveAdd << 1);
	}
	//Disable Genaral Call
	CLR_BIT(TWAR,0);
	
	//Enable ACKnowledge
	SET_BIT(TWCR,6);
	
	//Enable TWI
	SET_BIT(TWCR,2);
}

		/*FRAME Functions*/
		
void TWI_sendStartCondition(void)
{

//Send Start Condition
SET_BIT(TWCR,5);

//Clear flag to start current job
SET_BIT(TWCR,7);

//wait for flag
while(0 == GET_BIT(TWCR,7));

//Check ACK == Start Condition ACK
while((TWSR & 0xF8) != 0x08);

}


void TWI_sendRepStartCondition(void)
{

//Send Start Conditiion
SET_BIT(TWCR,5);

//Clear flag to start current job
SET_BIT(TWCR,7);

//wait for flag
while(0 == GET_BIT(TWCR,7));

//Check ACK == Repeated SC ACK
while((TWSR & 0xF8) != 0x10);
	
}


void TWI_sendStopCondition(void)
{
//Send Stop Conditiion
SET_BIT(TWCR,4);

//Clear flag to start current job
SET_BIT(TWCR,7);

/*
//wait for flag [Optional]
while(0 == GET_BIT(TWCR,7));
*/	
}


void TWI_sendSlaveAddWithRead(u8 slaveAdd)
{
	if (slaveAdd<128)
	{
		//Send Slave address
		TWDR = (slaveAdd << 1);
		
		//Select read op
		SET_BIT(TWDR,0);
		
				//Clear Start Condition Bit
				CLR_BIT(TWCR,5);
				
				//Clear flag to start current job
				SET_BIT(TWCR,7);

				//wait for flag
				while(0 == GET_BIT(TWCR,7));

				//Check ACK == Slave address + Read request ACK
				while((TWSR & 0xF8) != 0x40);	
	}
	
}


void TWI_sendSlaveAddWithWrite(u8 slaveAdd)
{
	if (slaveAdd<128)
	{
		//Send Slave address
		TWDR = (slaveAdd << 1);
		
		//Select write op
		CLR_BIT(TWDR,0);
		
			//Clear Start Condition Bit
			CLR_BIT(TWCR,5);
			
			//Clear flag to start current job
			SET_BIT(TWCR,7);

			//wait for flag
			while(0 == GET_BIT(TWCR,7));

			//Check ACK == Slave address + write request ACK
			while((TWSR & 0xF8) != 0x18);
	} 
		
}


void TWI_sendMasterDataByte(u8 TxData)
{
//Write Data into Data REG
TWDR = TxData;

			//Clear flag to start current job
			SET_BIT(TWCR,7);

			//wait for flag
			while(0 == GET_BIT(TWCR,7));

			//Check ACK == Master terminal Data ACK
			while((TWSR & 0xF8) != 0x28);
}


void TWI_readMasterDataByte(u8* RxData)
{
			//Clear flag to start current job
			SET_BIT(TWCR,7);

			//wait for flag
			while(0 == GET_BIT(TWCR,7));

			//Check ACK == Master Has recieved Data Byte with ACK
			while((TWSR & 0xF8) != 0x50);
			
	//Read Data from Data REG		
	*RxData = TWDR;	
}




