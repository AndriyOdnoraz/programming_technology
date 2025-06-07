/*
 * led.h
 *
 *  Created on: Jun 4, 2025
 *      Author: А1
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK_SLOW,
    LED_BLINK_FAST,
    LED_BLINK_SOS
} led_mode_t;

void led_init(void);
void led_setmode(led_mode_t mode);
void led_update(void);

#endif /* INC_LED_H_ */
