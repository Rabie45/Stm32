/*
 * main.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdal
 */

#include "main.h"
#include <string.h>
#define TRUE 1
#define FALSE 0
UART_HandleTypeDef uart;

void USART2_Init(void);
void Error_Handler();
char *user_data = "The application is running\r\n";
int main(void) {
	RCC_OscInitTypeDef osc_init;
	RCC_ClkInitTypeDef clk_init;
	uint8_t msg[100];
	HAL_Init();
	USART2_Init();
	uint16_t len = strlen(user_data);
	HAL_UART_Transmit(&uart, (uint8_t*) user_data, len, HAL_MAX_DELAY);

	memset(&osc_init, 0, sizeof(osc_init));
	osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	osc_init.HSEState = RCC_HSE_BYPASS;
	if (HAL_RCC_OscConfig(&osc_init) != HAL_OK) {
		Error_Handler();
	}
	memset(&clk_init, 0, sizeof(clk_init));
	clk_init.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1
			| RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_HCLK;
	clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;
	clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
	clk_init.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
	__HAL_RCC_HSI_DISABLE();
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	USART2_Init();
	memset(msg, 0, sizeof(msg));
	sprintf(msg, "SYSCLK : %ld\r\n", HAL_RCC_GetSysClockFreq());
	HAL_UART_Transmit(&uart, (uint8_t*) msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "HCLK : %ld\r\n", HAL_RCC_GetHCLKFreq());
	HAL_UART_Transmit(&uart, (uint8_t*) msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "PCLK1 : %ld\r\n", HAL_RCC_GetPCLK1Freq());
	HAL_UART_Transmit(&uart, (uint8_t*) msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "PCLK2 : %ld\r\n", HAL_RCC_GetPCLK2Freq());
	HAL_UART_Transmit(&uart, (uint8_t*) msg, strlen(msg), HAL_MAX_DELAY);

}

void USART2_Init(void) {

	uart.Instance = USART2;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.BaudRate = 115200;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	if (HAL_OK != HAL_UART_Init(&uart)) {
		//error
		Error_Handler();
	}

}
void Error_Handler() {
	while (1)
		;
}
