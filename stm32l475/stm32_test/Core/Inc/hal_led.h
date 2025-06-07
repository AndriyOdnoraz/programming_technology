#ifndef INC_HAL_LED_H_
#define INC_HAL_LED_H_

#include "stdint.h"

void LED_Pin_Set(void);

void LED_Pin_Reset(void);

uint32_t LED_Tick_get(void);

#endif /* INC_HAL_LED_H_ */