#include "uart_driver.h"

void UART_Init(uart_handle_t *uart){
	UART_configration_WordLenth(uart->Instance,uart->Init.dataLenth);
	UART_configure_NoStopBit(uart->Instance,uart->Init.stopbit);
	UART_configration_OverSampling(uart->Instance,uart->Init.overSampling);	
	UART_configration_Baudrate(uart->Instance,uart->Init.buadRate);
	UART_Receive_Enable(uart->Instance,uart->Init.mode);
	UART_Transmission_Enable(uart->Instance,uart->Init.mode);
	UART_Enable(uart->Instance,1);
	uart->TXstate  = HAL_I2C_STATE_READY;
	uart->RXstate  = HAL_I2C_STATE_READY;
	uart->Error_code = HAL_UART_ERROR_NONE;
	
}
void UART_TX(uart_handle_t *uart,uint32_t *TXBuffer,uint32_t size){
	uart->pTXBuffer=TXBuffer;
	uart->TXsize=size;
	uart->TXcount=size;
	uart->TXstate=HAL_I2C_STATE_BUSY_TX;
	UART_Enable(uart->Instance,1);
	UART_Transmitter_Enable_interrupt(uart->Instance,1);
}
void UART_RX(uart_handle_t *uart,uint32_t *RXBuffer,uint32_t size){
	uint32_t data;
uart->pRXBuffer=RXBuffer;
	uart->RXsize=size;
	uart->RXcount=size;
	uart->RXstate=HAL_I2C_STATE_BUSY_RX;
	UART_Enable(uart->Instance,1);
	UART_Error_interrupt_Enable(uart->Instance,1);
	UART_parity_interrupt_Enable(uart->Instance,1);
	data=uart->Instance->RDR;
	UART_Receive_Enable_interrupt(uart->Instance,1);
}
void UART_Enable(USART_TypeDef *uart,uint32_t onoff){
if(onoff == USART_UART_ENABLE )
	uart->CR1|=USART_REG_RC1_UE;
else
	uart->CR1&=~USART_REG_RC1_UE;
}
void UART_Transmission_Enable(USART_TypeDef *uart,uint32_t onoff){
if(onoff&USART_REG_RC1_TE)
	uart->CR1 |=USART_REG_RC1_TE;
else
	uart->CR1 &=~USART_REG_RC1_TE;
}

void UART_Receive_Enable(USART_TypeDef *uart,uint32_t onoff){
if(onoff&USART_REG_RC1_RE)
	uart->CR1 |= USART_REG_RC1_RE;
else
	uart->CR1 &= ~USART_REG_RC1_RE;

}

void UART_Receive_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff){
	if(onoff==USART_RECIVE_INTERRUPT_ENABLE)
		uart->CR1 |=USART_REG_RC1_RXNIE;
	else
		uart->CR1 &=~USART_REG_RC1_RXNIE;
}
void UART_Transmitter_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff){
if(onoff==USART_TRANSMISSION_INTERRUPT_ENABLE)
		uart->CR1 |=USART_REG_RC1_TXEIE;
	else
		uart->CR1 &=~USART_REG_RC1_TXEIE;
}

void UART_configration_OverSampling(USART_TypeDef *uart,uint32_t sample){
	if(sample == USART_8bit_OVERSAMPLE)
		uart->CR1 |=USART_REG_RC1_OVER8;
	else
		uart->CR1 &= ~USART_REG_RC1_OVER8;
}

void UART_configration_Baudrate(USART_TypeDef *uart,uint32_t datarate){
	
	if(datarate == USART_BAUDRATE_9600)
		uart->BRR =USART_BAUDRATE_9600;
	else
		uart->BRR =USART_BAUDRATE_115200;
	
}
void UART_configration_WordLenth(USART_TypeDef *uart,uint32_t length){
if(length==USART_8WORDLENGHT){
	uart->CR1 &=~USART_REG_RC1_M0;
	uart->CR1 &=~USART_REG_RC1_M1;
}
else if(length==USART_9WORDLENGHT){
uart->CR1 |=USART_REG_RC1_M0;
uart->CR1 &=~USART_REG_RC1_M1;
}
else if(length==USART_7WORDLENGHT){
uart->CR1 |=USART_REG_RC1_M0;
uart->CR1 |=USART_REG_RC1_M1;
}
}
void UART_configure_NoStopBit(USART_TypeDef *uart,uint32_t stopbits){
	if(stopbits == USART_1STOPBIT)
		uart->CR1 |= (stopbits<<12);
	else if(stopbits == USART_1_2STOPBIT)
		uart->CR1 |= (stopbits<<12);
	else if(stopbits == USART_3_2STOPBIT)
		uart->CR1 |= (stopbits<<12);
	else if(stopbits == USART_2STOPBIT)
		uart->CR1 |= (stopbits<<12);
}
void UART_Error_interrupt_Enable(USART_TypeDef *uart,uint32_t onoff){
	if(onoff == USART_ERROR_INT_ENABLE)
	uart->CR3 |= USART_REG_CR3_EIE;
	else
	uart->CR3 &= ~USART_REG_CR3_EIE;
}
void UART_parity_interrupt_Enable(USART_TypeDef *uart,uint32_t onoff){
	if(onoff)
		uart->CR1 |= USART_REG_RC1_PEIE;
	else
		uart->CR1 &= ~USART_REG_RC1_PEIE;
}
void UART_clear_Error_Flag(uart_handle_t *uart){
	
uart->Instance->ICR|=USART_REG_ICR_CMCF;
uart->Instance->ICR|=USART_REG_ICR_PECF;
uart->Instance->ICR|=USART_REG_ICR_FECF;
uart->Instance->ICR|=USART_REG_ICR_NCF;
uart->Instance->ICR|=USART_REG_ICR_TCCF;

}
void UART_Handle_interrupt(uart_handle_t *uart){
uint32_t tmp1,tmp2;
	tmp1=(uart->Instance->CR1 & USART_REG_RC1_PEIE); 
	tmp2=(uart->Instance->ISR & USART_REG_SR_PE_FLAG);
	if(tmp1 &&tmp2){
		uart->Error_code =HAL_UART_ERROR_PE;
		UART_clear_Error_Flag(uart);
	}
	tmp1=(uart->Instance->CR3 & USART_REG_CR3_EIE); 
	tmp2=(uart->Instance->ISR & USART_REG_SR_FE_FLAG);
	
	if(tmp1 &&tmp2){
		uart->Error_code =HAL_UART_ERROR_PE;
		UART_clear_Error_Flag(uart);
	}
	
	tmp1=(uart->Instance->CR1 & USART_REG_RC1_TXEIE); 
	tmp2=(uart->Instance->ISR & USART_REG_SR_TXE_FLAG);
	
	if(tmp1 &&tmp2){
	UART_TXE_handle_interrupt(uart);
	}
	tmp1=(uart->Instance->CR1 & USART_REG_RC1_TCIE); 
	tmp2=(uart->Instance->ISR & USART_REG_SR_TC_FLAG);
	
	if(tmp1 &&tmp2){
	UART_TC_handle_interrupt(uart);
	}
	tmp1=(uart->Instance->CR1 & USART_REG_RC1_RXNIE); 
	tmp2=(uart->Instance->ISR & USART_REG_SR_RXNE_FLAG);
	
	if(tmp1 &&tmp2){
	UART_RXNIE_handle_interrupt(uart);
	}
}
void UART_RXNIE_handle_interrupt(uart_handle_t *uart){
	uint32_t tmp;
	tmp=uart->RXstate;
	if(tmp == HAL_I2C_STATE_BUSY_RX){
		if(uart->Init.parity == UART_PARITY_NONE)
			*uart->pRXBuffer++ =(uint8_t)uart->Instance->RDR & (uint8_t)0x00FF;
		else
			*uart->pRXBuffer++ =(uint8_t)uart->Instance->RDR & (uint8_t)0x007F;
	
	if(--uart->RXcount ==0)
	UART_Receive_Enable(uart->Instance,0);
	UART_parity_interrupt_Enable(uart->Instance,0);
	UART_Error_interrupt_Enable(uart->Instance,0);
	uart->RXstate =HAL_I2C_STATE_READY;
	}
	

}
void UART_TC_handle_interrupt(uart_handle_t *uart){
	UART_TC_Enable_interrupt(uart->Instance,0);
	uart->TXstate = HAL_I2C_STATE_READY;

}

void UART_TXE_handle_interrupt(uart_handle_t *uart){
	uint32_t tmp;
	uint8_t data;
	
	tmp=uart->TXstate;
	if(tmp == HAL_I2C_STATE_BUSY_TX){
	data= (uint8_t)*uart->pTXBuffer++ & (uint8_t)0x00FF;
		uart->Instance->TDR =data;
		if(--uart->TXcount ==0){
				UART_Transmitter_Enable_interrupt(uart->Instance,0);
			UART_TC_Enable_interrupt(uart->Instance,1);
 }
	}

}
void UART_TC_Enable_interrupt(USART_TypeDef *uart,uint32_t onoff){
	if(onoff)
		uart->CR1 |= USART_REG_RC1_TCIE;
	else
		uart->CR1 &= ~USART_REG_RC1_TCIE;
}
