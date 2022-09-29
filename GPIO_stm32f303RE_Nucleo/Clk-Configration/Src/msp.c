/*
 * msp.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdal
 */

#include "stm32f3xx_hal.h"

void HAL_MspInit(void)
{
  //1. set up the priorty group
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	//2.enable bus exception mem, and others
	SCB->SHCSR |= (1<<18);
	SCB->SHCSR |= (1<<17); // memfault enable
	SCB->SHCSR |= (1<<16); // bus fault enable
	//3. configure the priorty

}

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	GPIO_Init.Alternate =GPIO_AF7_USART2;
	GPIO_Init.Mode = GPIO_MODE_AF_PP;
	GPIO_Init.Pin =GPIO_PIN_2;
	GPIO_Init.Speed =GPIO_SPEED_FREQ_LOW;
	GPIO_Init.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_Init);
	GPIO_Init.Pin =GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA, &GPIO_Init);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
}
