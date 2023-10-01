/*
 * TWI_interface.h
 *
 * Created: 10/6/2022 12:30:49 PM
 *  Author: Mohamed Nabil
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

		/*MAIN Functions*/
		
		/*INIT Functions*/	
void TWI_initMaster					(void);
void TWI_initSlave					(u8 slaveAdd); //Add->address
	
		/*FRAME Functions*/
void TWI_sendStartCondition			(void);
void TWI_sendRepStartCondition		(void);
void TWI_sendStopCondition			(void);

void TWI_sendSlaveAddWithRead		(u8 slaveAdd);
void TWI_sendSlaveAddWithWrite		(u8 slaveAdd);

void TWI_sendMasterDataByte			(u8 TxData);
void TWI_readMasterDataByte			(u8* RxData);




#endif /* I2C_INTERFACE_H_ */