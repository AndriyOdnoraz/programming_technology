
#ifdef TEST

#include "unity.h"
#include "led.h"
#include "mock_hal_led.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_led_init(void)
{
    LED_Pin_Reset_Expect();
    LED_Init();
}

void test_led_on(void)
{
    LED_Tick_get_IgnoreAndReturn(42);
    LED_SetMode(LED_ON);
    LED_Pin_Set_Expect();
    LED_Update();
}

void test_led_off(void)
{
    LED_Tick_get_IgnoreAndReturn(42);
    LED_SetMode(LED_OFF);
    LED_Pin_Reset_Expect();
    LED_Update();
}

#endif // TEST
