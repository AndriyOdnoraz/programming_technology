/*
 * led.c
 *
 *  Created on: Jun 4, 2025
 *      Author: Аndrii
 */

#include "led.h"
#include "hal_led.h"
#include "stdint.h"

static LED_Mode current_mode = LED_OFF;
static uint32_t last_toggle_time = 0;
static uint8_t led_state = 0;

void LED_Init(void) {
    LED_Pin_Reset();
}

void LED_SetMode(LED_Mode mode) {
    current_mode = mode;
    led_state = 0;
    last_toggle_time = LED_Tick_get();
}

void LED_Update(void) {
    uint32_t current_time = LED_Tick_get();

    switch(current_mode) {
        case LED_OFF:
            LED_Pin_Reset();
            break;

        case LED_ON:
            LED_Pin_Set();
            break;

        case LED_BLINK_SLOW:
            if(current_time - last_toggle_time >= 500) {
                last_toggle_time = current_time;
                led_state ^= 1;
                if (led_state)
                {
                    LED_Pin_Set();
                }
                else
                {
                    LED_Pin_Reset();
                }
            }
            break;

        case LED_BLINK_FAST:
            if(current_time - last_toggle_time >= 100) {
                last_toggle_time = current_time;
                led_state ^= 1;
                if (led_state)
                {
                    LED_Pin_Set();
                }
                else
                {
                    LED_Pin_Reset();
                }
            }
            break;

        case LED_BLINK_SOS: {
            static const uint16_t sos_pattern[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};
            static uint8_t pattern_index = 0;

            if(current_time - last_toggle_time >= sos_pattern[pattern_index]) {
                last_toggle_time = current_time;
                led_state ^= 1;
                pattern_index = (pattern_index + 1) % (sizeof(sos_pattern)/sizeof(sos_pattern[0]));
                if (led_state)
                {
                    LED_Pin_Set();
                }
                else
                {
                    LED_Pin_Reset();
                }
            }
            break;
        }
    }
}
