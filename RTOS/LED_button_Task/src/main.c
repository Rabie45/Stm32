/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f3xx.h"
#include "stm32f3xx_nucleo.h"
#include "FreeRTOS.h"
#include "task.h"
#include "string.h"
#include "SEGGER_SYSVIEW.h"
//extern void initialise_monitor_handles();

//some macros
#define TRUE 1
#define FALSE 0
#define AVAILABLE TRUE
#define NOT_AVAILABLE FALSE

#define ISPRESSED 1
#define NOT_AVAILABLE 0
uint16_t buttomValue=GPIO_PIN_RESET;
TaskHandle_t xTaskHandler1 = NULL;
TaskHandle_t xTaskHandler2 = NULL;
TaskFunction_t pxTaskCode;

void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG);
void USART2_init(void);
void GPIO_Init();
void Error_handler();
void prm(char *msg);

void ButtonTask(void *params);
void LEDTask(void *params);
UART_HandleTypeDef uart;
char user_data[250];

uint16_t UART_ACCESS_KEY = AVAILABLE;

int main(void) {

	DWT->CTRL |=(1<<0);
	//initialise_monitor_handles();
	HAL_Init();
	GPIO_Init();
	USART2_init();

	//sprintf(user_data,"the app is running \r\n");
	//prm(user_data);
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();
	xTaskCreate(LEDTask, "LED Task", 500, NULL, 2,
			NULL);
	xTaskCreate(ButtonTask, "Button Task", 500, NULL, 2,
			NULL);

	vTaskStartScheduler();
	for (;;);
}

void LEDTask(void *params) {

	while (1) {

		if(buttomValue == GPIO_PIN_SET)
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		taskYIELD();

	}
}
void ButtonTask(void *params) {
	while (1) {
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == GPIO_PIN_RESET)
		buttomValue = !buttomValue;

		taskYIELD();

	}

}
void USART2_init(void) {

	uart.Instance = USART2;
	uart.Init.BaudRate = 115200;
	uart.Init.Mode = USART_MODE_TX_RX;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = USART_STOPBITS_1;
	uart.Init.Parity = USART_PARITY_NONE;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	while (HAL_UART_Init(&uart) != HAL_OK) {
		Error_handler();
	}

}
void GPIO_Init(){

	GPIO_InitTypeDef led_gpio,button_gpio;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	led_gpio.Mode=GPIO_MODE_OUTPUT_PP;
	led_gpio.Pin=GPIO_PIN_5;
	led_gpio.Speed=GPIO_SPEED_FREQ_MEDIUM;
	led_gpio.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA,&led_gpio);

	button_gpio.Mode=GPIO_MODE_INPUT;
	button_gpio.Pin=GPIO_PIN_13;
	button_gpio.Speed=GPIO_SPEED_FREQ_MEDIUM;
	button_gpio.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC,&button_gpio);

}
void Error_handler() {

	while (1)
		;
}
void prm(char *msg) {
	uint16_t len = strlen(msg);
	//HAL_UART_Transmit(&uart, (uint8_t *) msg, len, HAL_MAX_DELAY);
for(uint32_t i=0;i<len;i++){
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)!= SET);
	USART_SendData(USART2,msg[i]);
}
}
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{
  /* Check the parameters */
 // assert_param(IS_USART_ALL_PERIPH(USARTx));
  //assert_param(IS_USART_DATA(Data));

  /* Transmit Data */
  USARTx->TDR = (Data & (uint16_t)0x01FF);
}
uint8_t USART_GetFlagStatus(USART_TypeDef* USARTx, uint32_t USART_FLAG)
{
  uint8_t bitstatus = RESET;

  if ((USARTx->ISR & USART_FLAG) != (uint16_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}
