/*
 * SPI_interface.h
 *
 * Created: 10/4/2022 1:26:59 PM
 *  Author: Mohamed Nabil
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_initMaster		(void);
void SPI_initSlave		(void);
void SPI_masterTrancieve(u8 TxData,u8* RxData);   //transmit & recieve at the same time
void SPI_slaveTrancieve(u8 TxData,u8* RxData);

#endif /* SPI_INTERFACE_H_ */