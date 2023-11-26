/*******************************************************
 * STM32F103x8_USART_driver.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Mohamed Nabil Mohamed
 *******************************************************
 *   This is USART Peripheral driver for STM32F103x8 MCU according to LQFP48 Package Specifications
 */
#include "../STM32F103C8_Drivers/inc/STM32F103x8_USART_driver.h"

/*
 * =============================================================================
 * 								Generic Variable
 * =============================================================================
 */


//index [0] --> USART1
//index [1] --> USART2
//index [2] --> USART3
UART_Config GLOBAL_UART_Config[3] ;


/*
 * =============================================================================
 * 								Generic Macros
 * =============================================================================
 */


/*
 * =============================================================================
 * 								Generic Functions
 * =============================================================================
 */



/*
 * =============================================================================
 * 							API Functions Definitions
 * =============================================================================
 */


/**===============================================================================================
 * @FName			- MCAL_UART_Init
 * @Brief 			- Initializes UART (Supported Features ASYNCH. ONLY)
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Parameter [in]	- UART_Config: All UART Configurations
 * @Return Value	- NONE
 * Note				- Supports For now ASYNCHRONOUS Mode & Clock 8 MHz
 */
void MCAL_UART_Init(USART_t* USARTx ,UART_Config* UART_Config){

	uint32_t Pclk , BRR;
	uint32_t USARTDIV_MUL100 ,DIV_Mantissa,DIV_Fraction,DIV_Mantissa_MUL100;



	//set GLOBAL_UART_Config for USARTx used
	if(USARTx == USART1){
		GLOBAL_UART_Config[0] = *UART_Config;

	}else if(USARTx == USART2){
		GLOBAL_UART_Config[1] = *UART_Config;

	}else if(USARTx == USART3){
		GLOBAL_UART_Config[2] = *UART_Config;
	}


	//enable clock for USARTx
	if(USARTx == USART1){
		RCC_USART1_CLK_EN();

	}else if(USARTx == USART2){
		RCC_USART2_CLK_EN();

	}else if(USARTx == USART3){
		RCC_USART3_CLK_EN();
	}

	//Enable USART Module
	USARTx->CR1 |= 1<<13 ;

	//Specify Tx/Rx Enable/Disable based on @ref UART_Mode_Define
	USARTx->CR1 |= UART_Config->UART_Mode;

	//Specify Payload_Length
	USARTx->CR1 |= UART_Config->Payload_Length;

	//Specify Parity
	USARTx->CR1 |= UART_Config->Parity;

	//Specify StopBits
	USARTx->CR2 |= UART_Config->StopBits;

	//Specify HW Flow Control
	USARTx->CR3 |= UART_Config->HwFlowCtrl;

	// set BaudRate Register (BRR)
	//PCLK1 For USART2 ,USART3
	//PCLK2 For USART1

	if(USARTx == USART1){

		Pclk =MCAL_RCC_GetPCLK2Freq();
	}else {
		Pclk =MCAL_RCC_GetPCLK1Freq();
	}

	USARTDIV_MUL100 = (25UL*Pclk) / (4UL*UART_Config->BaudRate);

	DIV_Mantissa_MUL100 = (USARTDIV_MUL100/100) * 100;

	DIV_Mantissa = DIV_Mantissa_MUL100 / 100 ;

	DIV_Fraction = ((USARTDIV_MUL100-DIV_Mantissa_MUL100)*16)/100;   //USARTDIV_MUL100 = DIV_Mantissa_MUL100 + (16*100*DIV_Fraction)


	BRR = (DIV_Mantissa << 4 ) | (DIV_Fraction & 0xF) ;

	USARTx->BRR = BRR;


	//Enable / Disable Interrupt
	//USART_CR1

	if(UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE){

		USARTx->CR1 |= UART_Config->IRQ_Enable;


		//Enable NVIC For USARTx IRQ
		if(USARTx == USART1){
			NVIC_IRQ37_USART1_ENABLE();

		}else if(USARTx == USART2){
			NVIC_IRQ38_USART2_ENABLE();

		}else if(USARTx == USART3){
			NVIC_IRQ39_USART3_ENABLE();
		}

	}




}


/**===============================================================================================
 * @FName			- MCAL_UART_DeInit
 * @Brief 			- Deinitializes UART (Supported Features ASYNCH. ONLY)
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Return Value	- NONE
 * Note				- Reset the model by RCC
 */
void MCAL_UART_DeInit(USART_t* USARTx){

	//Disable NVIC For USARTx IRQ
	if(USARTx == USART1){
		NVIC_IRQ37_USART1_DISABLE();
		RCC_USART1_CLK_RESET();

	}else if(USARTx == USART2){
		NVIC_IRQ38_USART2_DISABLE();
		RCC_USART2_CLK_RESET();
	}else if(USARTx == USART3){
		NVIC_IRQ39_USART3_DISABLE();
		RCC_USART3_CLK_RESET();
	}


}

/**===============================================================================================
 * @FName			- MCAL_UART_GPIO_Set_Pins
 * @Brief 			- Set GPIO pins to UART using AFIO Based on STM32F103x8 LQFP48 Package
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Return Value	- NONE
 * Note				-This Function should be used after Initializations
 */
void MCAL_UART_GPIO_Set_Pins(USART_t* USARTx){

	GPIO_PinConfig_t PinConfig;

	if(USARTx == USART1){
		//---------------------//
		//Tx  --> PA9
		//Rx  --> PA10
		//CTS --> PA11
		//RTS --> PA12
		//---------------------//

		//Tx  --> PA9
		PinConfig.GPIO_PinNumber = GPIO_PIN_9;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinConfig);

		//Rx  --> PA10
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		if(GLOBAL_UART_Config[0].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[0].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//CTS --> PA11
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


		if(GLOBAL_UART_Config[0].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[0].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//RTS --> PA12
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


	}else if(USARTx == USART2){

		//---------------------//
		//Tx  --> PA2
		//Rx  --> PA3
		//CTS --> PA0
		//RTS --> PA1
		//---------------------//

		//Tx  --> PA2
		PinConfig.GPIO_PinNumber = GPIO_PIN_2;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinConfig);

		//Rx  --> PA3
		PinConfig.GPIO_PinNumber = GPIO_PIN_3;
		PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinConfig);


		if(GLOBAL_UART_Config[1].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[1].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//CTS --> PA0
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


		if(GLOBAL_UART_Config[1].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[1].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//RTS --> PA1
			PinConfig.GPIO_PinNumber = GPIO_PIN_1;
			PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}


	}else if(USARTx == USART3){

		//---------------------//
		//Tx  --> PB10
		//Rx  --> PB11
		//CTS --> PB13
		//RTS --> PB14
		//---------------------//

		//Tx  --> PB10
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinConfig);

		//Rx  --> PB11
		PinConfig.GPIO_PinNumber = GPIO_PIN_11;
		PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinConfig);


		if(GLOBAL_UART_Config[2].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[2].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//CTS --> PB13
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}


		if(GLOBAL_UART_Config[2].HwFlowCtrl == UART_HwFlowCtrl_CTS || GLOBAL_UART_Config[2].HwFlowCtrl == UART_HwFlowCtrl_RTS_CTS )
		{
			//RTS --> PB14
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}

	}



}


/**===============================================================================================
 * @FName			- MCAL_UART_SendData
 * @Brief 			- Send data Buffer on UART
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Parameter [in] 	- pTxBuffer: Buffer to be sent
 * @Parameter [in] 	- PollingEn: Enable Polling for Tx data register Empty or Disable it
 *
 * @Return Value	- NONE
 * Note				- UART should be Initialized First
 *
 * 					  -	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
						the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
						because it is replaced by the parity.
						When receiving with the parity enabled, the value read in the MSB bit is the received parity
						bit.
 */
void MCAL_UART_SendData(USART_t* USARTx, uint16_t *pTxBuffer,enum Polling_mechanism PollingEn){



	//poll for TXE Pin
	if(PollingEn == enable){
		/*	Status register (USART_SR)
		 *
	Bit 7 TXE: Transmit data register empty
	This bit is set by hardware when the content of the TDR register has been transferred into
	the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It
	is cleared by a write to the USART_DR register.
	0: Data is not transferred to the shift register
	1: Data is transferred to the shift register)
	Note: This bit is used during single buffer transmission.*/

		while( GET_BIT(USARTx->SR,7) == 0 ) ; //wait
	}

	//set GLOBAL_UART_Config for USARTx used
	if(USARTx == USART1){

		//Check the USART Word Length item for 9BIT or 8BIT on a frame
		if(GLOBAL_UART_Config[0].Payload_Length == UART_Payload_Length_9B){

			USARTx->DR = (*pTxBuffer & (uint16_t)0x1FF);

		}else{

			USARTx->DR = (*pTxBuffer & (uint16_t)0xFF);

		}


	}else if(USARTx == USART2){

		//Check the USART Word Length item for 9BIT or 8BIT on a frame
		if(GLOBAL_UART_Config[1].Payload_Length == UART_Payload_Length_9B){

			USARTx->DR = (*pTxBuffer & (uint16_t)0x1FF);

		}else{

			USARTx->DR = (*pTxBuffer & (uint16_t)0xFF);

		}


	}else if(USARTx == USART3){

		//Check the USART Word Length item for 9BIT or 8BIT on a frame
		if(GLOBAL_UART_Config[2].Payload_Length == UART_Payload_Length_9B){

			USARTx->DR = (*pTxBuffer & (uint16_t)0x1FF);

		}else{

			USARTx->DR = (*pTxBuffer & (uint16_t)0xFF);

		}

	}




}

/**===============================================================================================
 * @FName			- MCAL_UART_Wait_TC
 * @Brief 			- Waits until Transfer complete flag is raised (TC)
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Return Value	- NONE
 * Note				- This function will trap the processor till all data Transfer is complete
 */
void MCAL_UART_Wait_TC(USART_t* USARTx){

	while(GET_BIT(USARTx->SR,6) == 0); //Wait

}



/**===============================================================================================
 * @FName			- MCAL_UART_ReceiveData
 * @Brief 			- Receive Data Buffer from UARTx
 * @Parameter [in] 	- USARTx: where x can be 1/2/3 depending on device
 * @Parameter [in] 	- pRxBuffer: Buffer to Receive data in
 * @Parameter [in] 	- PollingEn: Enable Polling for Tx data register Empty or Disable it
 *
 * @Return Value	- NONE
 * Note				- UART should be Initialized First
 *
 * 					  -	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
						the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
						because it is replaced by the parity.
						When receiving with the parity enabled, the value read in the MSB bit is the received parity
						bit.
 */
void MCAL_UART_ReceiveData(USART_t* USARTx, uint16_t* pRxBuffer,enum Polling_mechanism PollingEn){

	UART_Config* Temp_UART_Config = NULL;

	//poll for RXNE Pin
	if(PollingEn == enable){
		/*	Status register (USART_SR)
		 *
		Bit 5 RXNE: Read data register not empty
		This bit is set by hardware when the content of the RDR shift register has been transferred to
		the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
		It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
		writing a zero to it. This clearing sequence is recommended only for multibuffer
		communication.
		0: Data is not received
		1: Received data is ready to be read.*/

		while( GET_BIT(USARTx->SR,5) == 0 ) ; //Wait
	}

	//set GLOBAL_UART_Config for USARTx used
	if(USARTx == USART1){
		Temp_UART_Config =	&GLOBAL_UART_Config[0] ;

	}else if(USARTx == USART2){
		Temp_UART_Config =	&GLOBAL_UART_Config[1] ;

	}else if(USARTx == USART3){
		Temp_UART_Config =	&GLOBAL_UART_Config[2] ;
	}



	//Check the USART Word Length item for 9BIT or 8BIT on a frame
	if(Temp_UART_Config->Payload_Length == UART_Payload_Length_9B){


		//Check if parity is Enabled
		if(Temp_UART_Config->Parity == UART_Parity_NONE){

			//Read all data register content
			*pRxBuffer	= (USARTx->DR & (uint16_t)0x1FF);
		}else{

			//Parity is on, Read only Least 8Bit from data register content
			*pRxBuffer	= (USARTx->DR & (uint16_t)0xFF);
		}


	}else{

		//Check if parity is Enabled
		if(Temp_UART_Config->Parity == UART_Parity_NONE){

			//Read Least 8Bit from data register content
			*pRxBuffer	= (USARTx->DR & (uint16_t)0xFF);

		}else{

			//Parity is on, Read only Least 7Bit from data register content
			*pRxBuffer	= (USARTx->DR & (uint16_t)0x7F);
		}

	}

}




/*
 * =============================================================================
 * 							ISR DEFINATIONS
 * =============================================================================
 */

/* USART1 global interrupt  */
void USART1_IRQHandler(void){

	GLOBAL_UART_Config[0].P_IRQ_CallBack();

}  


/* USART2 global interrupt */
void USART2_IRQHandler(void){

	GLOBAL_UART_Config[1].P_IRQ_CallBack();


}        			


/* USART3 global interrupt */
void USART3_IRQHandler(void){

	GLOBAL_UART_Config[2].P_IRQ_CallBack();

}        			






