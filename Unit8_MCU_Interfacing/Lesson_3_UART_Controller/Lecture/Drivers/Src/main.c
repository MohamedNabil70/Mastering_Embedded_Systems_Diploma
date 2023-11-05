/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Nabil Mohamed
 * @brief          : Unit8_Lesson3_UART_Controller
 * 					 [CASE Study 2 with Debugging : using Interrupt mechanism]
 *
 *
 ******************************************************************************
 *		This application is used to test My USART driver for STM32F103x8 Based on LQFP48 Package.
 *		it is required to communicate with Virtual Terminal Through USART1,USART2,USART3 to test
 *		my Driver APIs especially send and receive for each USART instance in the Package using
 *		the following configurations:
 *
 *      BaudRate = 115200
 *      Parity = None
 *      Payload_width = 8 bit
 *      Stop Bits = 1
 *      Flow Control = None
 *		IRQ_Enable FOR RXNE Pin
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//-----------------------------
//Includes
//-----------------------------

//UTILS
#include "STM32F103x8.h"

//MCALL
#include "STM32F103x8_GPIO_driver.h"
#include "STM32F103x8_USART_driver.h"

extern void delay_ms(uint32_t time);

void clock_init(void){

	//Enable clock to AFIO
	RCC_AFIO_CLK_EN();
	//Enable clock to port A
	RCC_GPIOA_CLK_EN();
	//Enable clock to port B
	RCC_GPIOB_CLK_EN();


}

uint16_t Buffer ;

void UART1_CallBack(void)
{

	MCAL_UART_ReceiveData(USART1 , &Buffer , disable);

	MCAL_UART_SendData(USART1, &Buffer , enable);
	MCAL_UART_SendData(USART2, &Buffer , enable);
	MCAL_UART_SendData(USART3, &Buffer , enable);

}

void UART2_CallBack(void)
{

	MCAL_UART_ReceiveData(USART2 , &Buffer , disable);

	MCAL_UART_SendData(USART1, &Buffer , enable);
	MCAL_UART_SendData(USART2, &Buffer , enable);
	MCAL_UART_SendData(USART3, &Buffer , enable);
}

void UART3_CallBack(void)
{

	MCAL_UART_ReceiveData(USART3 , &Buffer , disable);

	MCAL_UART_SendData(USART1, &Buffer , enable);
	MCAL_UART_SendData(USART2, &Buffer , enable);
	MCAL_UART_SendData(USART3, &Buffer , enable);

}


int main(void)
{
	//Initializations
	clock_init();


	UART_Config UART_Cnfg;

	//USART1 init
	UART_Cnfg.BaudRate 			= UART_BaudRate_115200;
	UART_Cnfg.UART_Mode 		= UART_Mode_TX_RX;
	UART_Cnfg.Parity 			= UART_Parity_NONE;
	UART_Cnfg.Payload_Length 	= UART_Payload_Length_8B;
	UART_Cnfg.StopBits			= UART_StopBits_1;
	UART_Cnfg.HwFlowCtrl		= UART_HwFlowCtrl_NONE;

	UART_Cnfg.IRQ_Enable		= UART_IRQ_Enable_RXNE;
	UART_Cnfg.P_IRQ_CallBack	= UART1_CallBack;

	MCAL_UART_Init(USART1, &UART_Cnfg);



	//USART2 init with same settings
	UART_Cnfg.IRQ_Enable = UART_IRQ_Enable_RXNE;
	UART_Cnfg.P_IRQ_CallBack	= UART2_CallBack;

	MCAL_UART_Init(USART2, &UART_Cnfg);


	//USART3 init with same settings
	UART_Cnfg.IRQ_Enable = UART_IRQ_Enable_RXNE;
	UART_Cnfg.P_IRQ_CallBack	= UART3_CallBack;

	MCAL_UART_Init(USART3, &UART_Cnfg);


	MCAL_UART_GPIO_Set_Pins(USART3);
	MCAL_UART_GPIO_Set_Pins(USART2);
	MCAL_UART_GPIO_Set_Pins(USART1);
	while(1)
	{

		//Do nothing

	}

}
