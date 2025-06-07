#include "main.h"

void LED_Pin_Set(void)
{
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
}

void LED_Pin_Reset(void)
{
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
}

uint32_t LED_Tick_get(void){
    return HAL_GetTick();
}