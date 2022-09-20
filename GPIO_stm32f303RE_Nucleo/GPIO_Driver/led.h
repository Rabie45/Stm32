#ifndef LED_H
#define LED_H
#include "gpio_driver.h"

#define GPIOA_PIN_5   5


#define LED_GREEN 	GPIOA_PIN_5

void led_init(void);
void led_turn_on(GPIO_TypeDef *GPIOx, uint16_t pin);
void led_turn_off(GPIO_TypeDef *GPIOx, uint16_t pin);

#endif
