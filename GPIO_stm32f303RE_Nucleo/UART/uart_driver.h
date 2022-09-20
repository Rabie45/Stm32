#ifndef  UART_DRIVER_H
#define  UART_DRIVER_H
#include "stm32f303xe.h"

typedef enum{
HAL_I2C_STATE_RESET=0x00,
HAL_I2C_STATE_READY=0x01,
HAL_I2C_STATE_BUSY=0x02,
HAL_I2C_STATE_BUSY_RX=0x03,
HAL_I2C_STATE_BUSY_TX=0x04,
HAL_I2C_STATE_ERROR=0x05
}uart_state_t;

typedef struct{
uint32_t buadRate;
uint32_t dataLenth;
uint32_t stopbit;	
uint32_t parity;
uint32_t mode;
uint32_t overSampling;
}uart_init_t;

typedef struct{
	USART_TypeDef *Instance;
	uart_state_t 	TXstate;
	uart_state_t 	RXstate;
	uart_init_t  	Init;
	uint32_t 			*pTXBuffer;
	uint32_t 			TXsize;
	uint32_t 			TXcount;
	uint32_t 			*pRXBuffer;
	uint32_t 			RXsize;
	uint32_t 			RXcount;
	uint32_t 			Error_code;
}uart_handle_t;
#define _HAL_RCC_ENABLE_USART1()  (RCC->APB2ENR |=(1<<14))
#define _HAL_RCC_ENABLE_USART2()  (RCC->APB1ENR |=(1<<17))
#define _HAL_RCC_ENABLE_USART3()	(RCC->APB1ENR |=(1<<18))	
#define _HAL_RCC_ENABLE_USART4()	(RCC->APB1ENR |=(1<<19))
#define _HAL_RCC_ENABLE_USART5()	(RCC->APB1ENR |=(1<<20))

#define UART_MODE_TX_RX                     			((uint32_t)(USART_REG_RC1_TE |USART_REG_RC1_RE))
#define UART_MODE_TX                      				((uint32_t)(USART_REG_RC1_TE) )
/******************************* RC1*********************/
#define USART_REG_RC1_UE ((uint32_t)1)  //UART_ENABLE
#define USART_UART_ENABLE 1
#define USART_UART_DISABLE 0
#define USART_REG_RC1_RE ((uint32_t)1<<2)
#define USART_RECIVE_ENABLE 1
#define USART_RECIVE_DISABLE 0
#define USART_REG_RC1_TE ((uint32_t)1<<3)
#define USART_TRANSMISSION_ENABLE 1
#define USART_TRANSMISSION_DISABLE 0
#define USART_REG_RC1_IDLEIE ((uint32_t)1<<4)
#define USART_REG_RC1_RXNIE  ((uint32_t)1<<5)
#define USART_RECIVE_INTERRUPT_ENABLE 1
#define USART_RECIVE_INTERRUPT_DISABLE 0
#define USART_REG_RC1_TCIE  ((uint32_t)1<<6)
#define USART_REG_RC1_TXEIE ((uint32_t)1<<7)
#define USART_TRANSMISSION_INTERRUPT_ENABLE 1
#define USART_TRANSMISSION_INTERRUPT_DISABLE 0
#define USART_REG_RC1_PEIE  ((uint32_t)1<<8)
#define USART_REG_RC1_PS 		((uint32_t)1<<9)
#define USART_REG_RC1_PCE 	((uint32_t)1<<10)
#define USART_REG_RC1_OVER8 ((uint32_t)1<<15)
#define USART_8bit_OVERSAMPLE 1
#define USART_16bit_OVERSAMPLE 0
#define USART_REG_RC1_M0 		((uint32_t)1<<11)
#define USART_REG_RC1_M1 		((uint32_t)1<<28)
#define USART_8WORDLENGHT	0
#define USART_9WORDLENGHT	1
#define USART_7WORDLENGHT	2

/*******************************RC2*********************/
#define USART_REG_RC2_STOP 		((uint32_t)1<<12)
#define USART_1STOPBIT 0
#define USART_1_2STOPBIT 1
#define USART_2STOPBIT 2
#define USART_3_2STOPBIT 3
/*****************SR************************/
#define USART_REG_SR_PE_FLAG  ((uint32_t)1<<0)
#define USART_REG_SR_FE_FLAG  ((uint32_t)1<<1)
#define USART_REG_SR_NE_FLAG ((uint32_t)1<<2)
#define USART_REG_SR_ORE_FLAG  ((uint32_t)1<<3)
#define USART_REG_SR_IDLE_FLAG  ((uint32_t)1<<4)
#define USART_REG_SR_RXNE_FLAG  ((uint32_t)1<<5)
#define USART_REG_SR_TC_FLAG  ((uint32_t)1<<6)
#define USART_REG_SR_TXE_FLAG  ((uint32_t)1<<7)
#define USART_REG_SR_LBDF_FLAG  ((uint32_t)1<<8)
#define USART_REG_SR_CTSIF_FLAG  ((uint32_t)1<<9)
#define USART_REG_SR_CTS_FLAG  ((uint32_t)1<<10)
#define USART_REG_SR_BUSY_FLAG  ((uint32_t)1<<16)

/************************ICR***************/
#define USART_REG_ICR_TCCF  ((uint32_t)1<<6)
#define USART_REG_ICR_PECF  ((uint32_t)1<<0)
#define USART_REG_ICR_FECF  ((uint32_t)1<<1)
#define USART_REG_ICR_NCF  ((uint32_t)1<<2)
#define USART_REG_ICR_CMCF  ((uint32_t)1<<17)
/**********************BRR***************************/
#define USART_REG_BRR  ((uint32_t)1<<0)
#define USART_BAUDRATE_9600  0x1D4C
#define USART_BAUDRATE_115200  0x271
#define USART_REG_CR3_EIE  ((uint32_t)1<<0)
#define USART_ERROR_INT_ENABLE 1
#define USART_ERROR_INT_DISABLE 0
#define USART_1 USART1
#define USART_2 USART2
#define USART_3 USART3
#define USART_4 UART4
#define USART_5 UART5


/*UART possible error codes */
#define HAL_UART_ERROR_NONE         ((uint32_t)0x00000000)   /*!< No error            */
#define HAL_UART_ERROR_PE           ((uint32_t)0x00000001)   /*!< Parity error        */
#define HAL_UART_ERROR_NE           ((uint32_t)0x00000002)   /*!< Noise error         */
#define HAL_UART_ERROR_FE           ((uint32_t)0x00000004)   /*!< Frame error         */
#define HAL_UART_ERROR_ORE          ((uint32_t)0x00000008)   /*!< Overrun error       */
#define HAL_UART_ERROR_DMA          ((uint32_t)0x00000010)   /*!< DMA transfer error  */
#define UART_PARITY_NONE                  				((uint32_t)0x00000000)
void UART_Init(uart_handle_t *uart);
void UART_TX(uart_handle_t *uart,uint32_t *TXBuffer,uint32_t size);
void UART_RX(uart_handle_t *uart,uint32_t *TXBuffer,uint32_t size);
void UART_Handle_interrupt(uart_handle_t *uart);
void UART_Error_interrupt_Enable(USART_TypeDef *uart,uint32_t onoff);
void UART_Enable(USART_TypeDef *uart,uint32_t onoff);
void UART_Transmission_Enable(USART_TypeDef *uart,uint32_t onoff);
void UART_Receive_Enable(USART_TypeDef *uart,uint32_t onoff);
void UART_Transmitter_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff);
void UART_Receive_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff);
void UART_configration_OverSampling(USART_TypeDef *uart,uint32_t sample);
void UART_configure_NoStopBit(USART_TypeDef *uart,uint32_t stopbits);
void UART_configration_Baudrate(USART_TypeDef *uart,uint32_t datarate);
void UART_configration_WordLenth(USART_TypeDef *uart,uint32_t length);
void UART_parity_interrupt_Enable(USART_TypeDef *uart,uint32_t onoff);
void UART_clear_Error_Flag(uart_handle_t *uart);
void UART_RXNIE_handle_interrupt(uart_handle_t *uart);
void UART_TC_handle_interrupt(uart_handle_t *uart);
void UART_TXE_handle_interrupt(uart_handle_t *uart);
void UART_TC_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff);
#endif
