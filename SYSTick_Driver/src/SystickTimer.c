/*
 * SystickTimer.c
 *
 *  Created on: Dec 22, 2022
 *      Author: abdal
 */

#include "SystickTimer.h"

void SystickDelay(uint32_t delay){
	SysTick->LOAD =STK_LOAD_VAL;
	SysTick->CTRL=STK_CTRL_EN|STK_CTRL_CLKSOURCE;
	SysTick->VAL =0;
	while(delay>0){
		while((SysTick->CTRL & STK_CTRL_COUNTFLAG) ==0){}
	delay--;
	}
	SysTick->CTRL=0;

}
