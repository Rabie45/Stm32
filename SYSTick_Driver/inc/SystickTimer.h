#include "stm32f3xx.h"



#define STK_CTRL_EN (1<<0)
#define STK_CTRL_COUNTFLAG (1<<16)
#define STK_CTRL_CLKSOURCE (1<<2)

#define STK_LOAD_VAL 8000

void SystickDelay(uint32_t delay);
