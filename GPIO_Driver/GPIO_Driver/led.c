#include "led.h"

void led_init(){
	gpio_pin_conf_t led_pin_conf;
	_HAL_RCC_GPIOA_ENABLE();
	
	led_pin_conf.pin =LED_GREEN;
	led_pin_conf .mode= HAL_PIN_OUTPUT_MODE;	
	led_pin_conf .op_type=HAL_PIN_OPTYPE_PUSH_PULL;
	led_pin_conf.speed = HAL_PIN_SPPED_MEDIUM;
	led_pin_conf .pull=HAL_PIN_NO_PULL_UP_NO_PULL_DOWN;
	hal_gpio_init(GPIOA,&led_pin_conf);
}

void led_turn_on(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	hal_gpio_write_to_pin(GPIOx,pin, 1);
	
}

void led_turn_off(GPIO_TypeDef *GPIOx, uint16_t pin)
{
	hal_gpio_write_to_pin(GPIOx,pin, 0);
	
}

/*void led_toggle(){
	if(hal_gpio_read_from_pin(GPIOA,5))
		led_turn_off(GPIOA,LED_GREEN);
	else
		led_turn_on(GPIOA,LED_GREEN);
}*/
