#include "gpio_driver.h"
void hal_gpio_init(GPIO_TypeDef* GPIOx,gpio_pin_conf_t* gpio_pin_conf){
	hal_gpio_configure_pin_mode(GPIOx,gpio_pin_conf->pin,gpio_pin_conf->mode);
	hal_gpio_configure_pin_speed(GPIOx,gpio_pin_conf->pin,gpio_pin_conf->speed);
	hal_gpio_configure_pin_otype(GPIOx,gpio_pin_conf->pin,gpio_pin_conf->op_type);
	hal_gpio_configure_pin_pull_up_down(GPIOx,gpio_pin_conf->pin,gpio_pin_conf->pull);
	//hal_gpio_configure_pin_alternate_fun(GPIOx,gpio_pin_conf->pin,gpio_pin_conf->alternate);


}
void hal_gpio_configure_pin_mode(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t mode){
	
	GPIOx->MODER |=(mode <<(2*pin_no));
	
}

void hal_gpio_configure_pin_speed(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t speed){
	
	GPIOx->OSPEEDR |=(speed << (2*pin_no));	
}

void hal_gpio_configure_pin_otype(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t op_type){
	
	GPIOx->OTYPER |=(op_type << pin_no);
}
void hal_gpio_configure_pin_pull_up_down(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t pull_up_down){
	
GPIOx->PUPDR |=(pull_up_down << (2*pin_no));
}

void hal_gpio_configure_pin_alternate_fun(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t alt_fun){
	if(pin_no< 7)
	GPIOx->AFR[0] |= (alt_fun << (4 * pin_no));
	else
	GPIOx->AFR[1] |= (alt_fun << (4 * (pin_no%8)));	
}

uint8_t hal_gpio_read_from_pin(GPIO_TypeDef* GPIOx,uint16_t pin_no){
	
	return ((GPIOx->IDR >> pin_no)&0x00000001);
}

void hal_gpio_write_to_pin(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t val)
{
	//led pa5
	if(val)
	GPIOx->ODR |=(1<<pin_no); 
	else
	GPIOx->ODR &=  ~(1 << pin_no);

}
