
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

void test_led_on(void)
{
    LED_Tick_get_IgnoreAndReturn(42);
    LED_SetMode(LED_ON);
    LED_Pin_Set_Expect();
    LED_Update();
}

#endif // TEST
