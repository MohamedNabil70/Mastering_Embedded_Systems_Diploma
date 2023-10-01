/*
 * EEPROM_program.c
 *
 * Created: 10/11/2022 6:57:20 AM
 *  Author: Mohamed Nabil
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "TWI_interface.h"
		
		/* HAL */
		#include "EEPROM_interface.h"
		
		

void EEPROM_writeByte(u16 byteAddress,u8 DataByte)
{
u8 localAddress =(u8) ((u8)( byteAddress >> 8) | EEPROM_FIXED_ADDRESS);  //0x50 = 0b01010000

//Send start condition
TWI_sendStartCondition();

//Send slave address with Write OP
TWI_sendSlaveAddWithWrite(localAddress);
 
//Send Byte Address
TWI_sendMasterDataByte((u8)byteAddress);  //take least 8 bits of byte address

//Send data byte
TWI_sendMasterDataByte(DataByte);

//send stop condition
TWI_sendStopCondition();

//Delay 5 ms to assure functionality [self timed write cycle] 
_delay_ms(5);	
}


void EEPROM_readByte(u16 byteAddress,u8* returnedByte)
{
u8 localAddress =(u8) ((u8)( byteAddress >> 8) | EEPROM_FIXED_ADDRESS);  //0x50 = 0b01010000

//Send start condition
TWI_sendStartCondition();

//Send slave address with Write OP
TWI_sendSlaveAddWithWrite(localAddress);

//Send Byte Address
TWI_sendMasterDataByte((u8)byteAddress);  //take least 8 bits of byte address


//Send Repeated start condition
TWI_sendRepStartCondition();

//Send slave address with Read OP
TWI_sendSlaveAddWithRead(localAddress);

//Read data byte
TWI_readMasterDataByte(returnedByte);

//send stop condition
TWI_sendStopCondition();

//Delay 5 ms to assure functionality [self timed write cycle]
_delay_ms(5);	
}	