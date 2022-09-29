/*
 * it.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdal
 */
#include "main.h"
extern UART_HandleTypeDef uart;
void SysTick_Handler(void){

HAL_IncTick();
HAL_SYSTICK_IRQHandler();
}
void USART2_IRQHandler(){
	HAL_UART_IRQHandler(&uart);


}
