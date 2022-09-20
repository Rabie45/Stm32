#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

//define your mcu
#include "stm32f303xe.h"



// intialize values of your mcu  

//GPIO port mode register (GPIOx_MODER) (x =A..H) page 237
#define HAL_PIN_OUTPUT_MODE 				((uint32_t)0x01)
#define HAL_PIN_INPUT_MODE 					((uint32_t)0x00)
#define HAL_PIN_ALTERNATE_MODE 			((uint32_t)0x02)
#define HAL_PIN_ANALOG_MODE 				((uint32_t)0x03)

//GPIO port output type register (GPIOx_OTYPER) (x = A..H) 0: Output push-pull (reset state)
//1: Output open-drain
#define HAL_PIN_OPTYPE_PUSH_PULL 				((uint32_t)0x00) //Output push-pull
#define HAL_PIN_OPTYPE_OPEN_DRAIN				((uint32_t)0x01) //Output open-drain
//GPIO port output speed register (GPIOx_OSPEEDR)
#define HAL_PIN_SPPED_LOW  						((uint32_t) 0x00)
#define HAL_PIN_SPPED_MEDIUM					((uint32_t) 0x01)
#define HAL_PIN_SPPED_HIGH						((uint32_t) 0x03)

//GPIO port pull-up/pull-down register (GPIOx_PUPDR)
#define HAL_PIN_NO_PULL_UP_NO_PULL_DOWN		((uint32_t) 0x00)
#define HAL_PIN_PULL_UP										((uint32_t) 0x01)				
#define HAL_PIN_PULL_DOWN									((uint32_t) 0x02)

// GPIOx base addres
#define GPIO_PORT_A GPIOA
#define GPIO_PORT_B GPIOB
#define GPIO_PORT_C GPIOC
#define GPIO_PORT_D GPIOD
#define GPIO_PORT_E GPIOE
#define GPIO_PORT_F GPIOF
#define GPIO_PORT_G GPIOG
#define GPIO_PORT_H GPIOH

//Enable prephiral 

// Device header
#define _HAL_RCC_GPIOH_ENABLE()		    (RCC->AHBENR |= (1 << 16))
#define _HAL_RCC_GPIOA_ENABLE()		    (RCC->AHBENR |= (1 << 17))
#define _HAL_RCC_GPIOB_ENABLE()		    (RCC->AHBENR |= (1 << 18))
#define _HAL_RCC_GPIOC_ENABLE()		    (RCC->AHBENR |= (1 << 19))
#define _HAL_RCC_GPIOD_ENABLE()		    (RCC->AHBENR |= (1 << 20))
#define _HAL_RCC_GPIOE_ENABLE()		    (RCC->AHBENR |= (1 << 21))
#define _HAL_RCC_GPIOF_ENABLE()		    (RCC->AHBENR |= (1 << 22))
#define _HAL_RCC_GPIOG_ENABLE()		    (RCC->AHBENR |= (1 << 23))


typedef struct{
	uint32_t  pin;
	uint32_t  mode;
	uint32_t  op_type;
	uint32_t  speed;
	uint32_t  pull;
	uint32_t  alternate;
}gpio_pin_conf_t;



void hal_gpio_init(GPIO_TypeDef* GPIOx,gpio_pin_conf_t* gpio_pin_conf);
uint8_t hal_gpio_read_from_pin(GPIO_TypeDef* GPIOx,uint16_t pin_no);
void hal_gpio_write_to_pin(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t val);
void hal_gpio_set_alt_function(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint16_t alt_fun);

void hal_gpio_configure_pin_mode(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t mode);
void hal_gpio_configure_pin_speed(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t speed);
void hal_gpio_configure_pin_otype(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t op_type);
void hal_gpio_configure_pin_pull_up_down(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t pull_up_down);
void hal_gpio_configure_pin_alternate_fun(GPIO_TypeDef* GPIOx,uint16_t pin_no,uint8_t alt_fun);
#endif
