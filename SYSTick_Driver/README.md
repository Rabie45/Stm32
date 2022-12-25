# SYSTickTimer Driver (NUCLEO-stm32f303RE)
- Using the datasheet of Cortex M to implemnt this driver 
## Registers Used in page 249:
- SysTick Control and Status Register (SYST_CSR) 
 - COUNTFLAG Returns 1 if timer counted to 0 since last time this was read.
 - CLKSOURCE Indicates the clock source:
	- 0 = external clock
 	- 1 = processor clock.
 - ENABLE Enables the counter:
        - 0 = counter disabled
	- 1 = counter enabled.
- SysTick Reload Value Register (SYST_RVR)
 - RELOAD Value to load into the SYST_CVR register when the counter is enabled and when it reaches 0.

## Algorithm:
- First LOAD the Value (ex 8000) as max value
- Enable the prephiral and configure the clock source
- Start with value 0
- While the flag not set decrease the value by one 
- Then close the Timer 



