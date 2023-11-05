## USART Controller Session

This application is used to test My USART driver for STM32F103x8 Based on LQFP48 Package.
it is required to communicate with Virtual Terminal Through USART1,USART2,USART3 to test
my Driver APIs especially send and receive for each USART instance in the Package using
the following configurations:

-BaudRate = 115200
-Parity = None
-Payload_width = 8 bit
-Stop Bits = 1
-Flow Control = None
-IRQ_Enable FOR RXNE Pin

### If you send any character through UARTx it will send it to UART1,UART2,and UART3
