#include "led_driver.h"
void set_led(uint8_t index,uint8_t sta)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0<<index, (GPIO_PinState)sta);
}
void toggle_led(uint8_t index)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0<<index);
}
void set_all_led(uint8_t sta)
{
	for(uint8_t i=0;i<8;i++)
	{
		set_led(i,sta);
	}
}
void led_driver_init(void)
{
	
}
