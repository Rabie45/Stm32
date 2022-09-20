#ifndef  UART_MAIN_H
#define UART_MAIN_H
#include "gpio_driver.h"
#include "uart_driver.h"
#define USART_TX_PIN 2
#define USART_RX_PIN 3
#define GPIO_PIN_AF2_UART2   7
uart_handle_t uart;
void  uart_gpio_init();

#endif
