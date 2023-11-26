/**************************************************
 * STM32F103x8_USART_driver.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 *
 **************************************************
 * This is USART Peripheral driver for STM32F103x8 MCU according to LQFP48 Package Specifications
 */

#ifndef INC_STM32F103x8_USART_driver_H_
#define INC_STM32F103x8_USART_driver_H_

//-----------------------------
//Includes
//-----------------------------

#include "../../STM32F103C8_Drivers/inc/BIT_MATH.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8_EXTI_driver.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8_GPIO_driver.h"
#include "../../STM32F103C8_Drivers/inc/STM32F103x8_RCC_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct {

	uint8_t				UART_Mode		;	//Specifies Tx/Rx Enable/Disable
											//This parameter must be set based on @ref UART_Mode_Define

	uint32_t			BaudRate	 	;	//This parameter configures the UART communication Baud Rate (symbol/s) == (Bit/s)
											//This parameter must be set based on @ref UART_BaudRate_Define

	uint8_t 			Payload_Length	;	//Specifies Word Length or Data size in Frame
											//This parameter must be set based on @ref UART_Payload_Length_Define

	uint8_t 			Parity			;	//Specifies The parity mode
											//This parameter must be set based on @ref UART_Parity_Define

	uint8_t 			StopBits		;	//Specifies The number of Stop Bits
											//This parameter must be set based on @ref UART_StopBits_Define

	uint8_t 			HwFlowCtrl 		;	//Specifies whether Hardware Flow Control mode is on or off
											//This parameter must be set based on @ref UART_HwFlowCtrl_Define

	uint8_t 			IRQ_Enable 		;	//Specifies whether Hardware USART IRQ TX/RX is EnableD or Disabled
											//This parameter must be set based on @ref UART_IRQ_Enable_Define


	void (*P_IRQ_CallBack)(void) 		;	//Sets the C function that will be called once the IRQ happens


}UART_Config;



//-----------------------------
//References Macros Configuration
//-----------------------------

//@ref UART_Mode_Define
#define UART_Mode_TX		(uint32_t)(1<<3)
#define UART_Mode_RX		(uint32_t)(1<<2)
#define UART_Mode_TX_RX 	((uint32_t)( 1<<3 | 1<<2 ))


//@ref UART_BaudRate_Define
#define UART_BaudRate_2400				2400
#define UART_BaudRate_9600              9600
#define UART_BaudRate_19200             19200
#define UART_BaudRate_57600             57600
#define UART_BaudRate_115200            115200
#define UART_BaudRate_230400            230400
#define UART_BaudRate_460800            460800
#define UART_BaudRate_921600            921600
#define UART_BaudRate_2250000           2250000
#define UART_BaudRate_4500000           4500000


//@ref UART_Payload_Length_Define
#define UART_Payload_Length_8B 		(uint32_t)0
#define UART_Payload_Length_9B 		(uint32_t)(1<<12)

//@ref UART_Parity_Define
#define UART_Parity_NONE			(uint32_t)0
#define UART_Parity_EVEN			(uint32_t)(1<<10)
#define UART_Parity_ODD				((uint32_t)( 1<<9 | 1<<10 ))

//@ref UART_StopBits_Define
#define UART_StopBits_Half			(uint32_t)(1<<12)
#define UART_StopBits_1				(uint32_t)0
#define UART_StopBits_1_Half		(uint32_t)(2<<12)
#define UART_StopBits_2				(uint32_t)(3<<12)

//@ref UART_HwFlowCtrl_Define
#define UART_HwFlowCtrl_NONE		(uint32_t)0
#define UART_HwFlowCtrl_RTS		    (uint32_t)(1<<8)
#define UART_HwFlowCtrl_CTS		    (uint32_t)(1<<9)
#define UART_HwFlowCtrl_RTS_CTS		((uint32_t)( 1<<9 | 1<<8 ))

//@ref UART_IRQ_Enable_Define
#define UART_IRQ_Enable_NONE		(uint32_t)0
#define UART_IRQ_Enable_TXE			(uint32_t)(1<<7)	//Transmit Data register empty
#define UART_IRQ_Enable_TC			(uint32_t)(1<<6) 	//Transmit complete
#define UART_IRQ_Enable_RXNE		(uint32_t)(1<<5)	//receive Data register not empty
#define UART_IRQ_Enable_PE			(uint32_t)(1<<8)	//Parity Error


enum Polling_mechanism {
	enable,
	disable
};

/*
 * ===============================================
 * APIs
 * ===============================================
 */

void MCAL_UART_Init(USART_t* USARTx ,UART_Config* UART_Config);
void MCAL_UART_DeInit(USART_t* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_t* USARTx);

void MCAL_UART_SendData(USART_t* USARTx, uint16_t* pTxBuffer,enum Polling_mechanism PollingEn);
void MCAL_UART_ReceiveData(USART_t* USARTx, uint16_t* pRxBuffer,enum Polling_mechanism PollingEn);

void MCAL_UART_Wait_TC(USART_t* USARTx);




//todo MCAL_USART_LIN_Init() 	//LIN
//todo MCAL_USART_Init()		//Synchronous
//todo MCAL_USART_DMA_Init()	//Multi Buffer communication


#endif /* INC_STM32F103x8_USART_driver_H_ */
