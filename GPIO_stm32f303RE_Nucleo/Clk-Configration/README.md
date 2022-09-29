To configure the clock source of neculeo board there is two important structs to control this process 
RCC_OscInitTypeDef osc_init
RCC_ClkInitTypeDef clk_init
configure each on of them and call its init function.... thats all as shown un main.c 
HAL_UART_TRANSMIT() used to check wheather the code work effecintly or not 
