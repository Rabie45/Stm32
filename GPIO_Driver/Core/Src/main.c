

#include "led.h"
void delay(void);
int main(void){
	
	led_init();
	
	while(1){
	led_turn_on(GPIOA,LED_GREEN);
		 delay();
			
		led_turn_off(GPIOA,LED_GREEN);
		delay();
		
	}
	
}
void delay(void)
{
    volatile int i;
    for(i=0; i<500000 ;i++);
}
