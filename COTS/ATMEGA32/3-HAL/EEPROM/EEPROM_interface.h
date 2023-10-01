/*
 * EEPROM_interface.h
 *
 * Created: 10/11/2022 6:57:37 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

	
#define EEPROM_FIXED_ADDRESS  0x50	
	
	
		/* MAIN FUNCTIONS*/
void EEPROM_writeByte(u16 byteAddress,u8 DataByte);
void EEPROM_readByte(u16 byteAddress,u8* returnedByte);


		/*Other Functions*/


#endif /* EEPROM_INTERFACE_H_ */