/*
 * led.h
 *
 *  Created on: Jun 4, 2025
 *      Author: А1
 */

#ifndef INC_LED_H_
#define INC_LED_H_

typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK_SLOW,
    LED_BLINK_FAST,
    LED_BLINK_SOS
} LED_Mode;

void LED_Init(void);
void LED_SetMode(LED_Mode mode);
void LED_Update(void);

#endif /* INC_LED_H_ */
