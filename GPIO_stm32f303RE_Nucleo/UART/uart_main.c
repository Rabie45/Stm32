#include "uart_main.h"


void uart_gpio_init(){
	gpio_pin_conf_t uart;
	_HAL_RCC_GPIOA_ENABLE(); 
	uart.pin= USART_RX_PIN;
	uart.mode = HAL_PIN_ALTERNATE_MODE;
	uart.pull =HAL_PIN_NO_PULL_UP_NO_PULL_DOWN;
	uart.op_type =HAL_PIN_OPTYPE_PUSH_PULL;
	uart.speed =HAL_PIN_SPPED_HIGH;
	hal_gpio_configure_pin_alternate_fun(GPIOA,USART_RX_PIN,GPIO_PIN_AF2_UART2);
	hal_gpio_init(GPIOA,&uart);
	
	uart.pin= USART_TX_PIN;
	uart.mode = HAL_PIN_ALTERNATE_MODE;
	uart.pull =HAL_PIN_NO_PULL_UP_NO_PULL_DOWN;
	uart.op_type =HAL_PIN_OPTYPE_PUSH_PULL;
	uart.speed =HAL_PIN_SPPED_HIGH;
	hal_gpio_configure_pin_alternate_fun(GPIOA,USART_TX_PIN,GPIO_PIN_AF2_UART2);
	hal_gpio_init(GPIOA,&uart);
	
}
uint8_t rx_buffer[4];
int main(){
uart_gpio_init();
_HAL_RCC_ENABLE_USART2(); 
	uart.Instance=USART_2;
	uart.Init.buadRate=USART_BAUDRATE_9600;
	uart.Init.dataLenth =USART_8WORDLENGHT;
	uart.Init.mode=UART_MODE_TX_RX;
	uart.Init.overSampling =USART_16bit_OVERSAMPLE;
	uart.Init.parity =HAL_UART_ERROR_NONE;
	uart.Init.stopbit=USART_1STOPBIT;
	
	UART_Init(&uart);
	NVIC_EnableIRQ(USART2_IRQn);
	while(1){
		while(uart.RXstate !=HAL_I2C_STATE_READY);
		UART_RX(&uart,rx_buffer,5);
	
	}
	
}
