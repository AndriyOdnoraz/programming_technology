/*
 * led.c
 *
 *  Created on: Jun 4, 2025
 *      Author: Аndrii
 */

#include "led.h"
#include "main.h"

static LED_Mode current_mode = LED_OFF;
static uint32_t last_toggle_time = 0;
static uint8_t led_state = 0;

void LED_Init(void) {
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
}

void LED_SetMode(LED_Mode mode) {
    current_mode = mode;
    led_state = 0;
    last_toggle_time = HAL_GetTick();
}

void LED_Update(void) {
    uint32_t current_time = HAL_GetTick();

    switch(current_mode) {
        case LED_OFF:
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
            break;

        case LED_ON:
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
            break;

        case LED_BLINK_SLOW:
            if(current_time - last_toggle_time >= 500) {
                last_toggle_time = current_time;
                led_state ^= 1;
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led_state ? GPIO_PIN_SET : GPIO_PIN_RESET);
            }
            break;

        case LED_BLINK_FAST:
            if(current_time - last_toggle_time >= 100) {
                last_toggle_time = current_time;
                led_state ^= 1;
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led_state ? GPIO_PIN_SET : GPIO_PIN_RESET);
            }
            break;

        case LED_BLINK_SOS: {
            static const uint16_t sos_pattern[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};
            static uint8_t pattern_index = 0;

            if(current_time - last_toggle_time >= sos_pattern[pattern_index]) {
                last_toggle_time = current_time;
                led_state ^= 1;
                pattern_index = (pattern_index + 1) % (sizeof(sos_pattern)/sizeof(sos_pattern[0]));
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, led_state ? GPIO_PIN_SET : GPIO_PIN_RESET);
            }
            break;
        }
    }
}
