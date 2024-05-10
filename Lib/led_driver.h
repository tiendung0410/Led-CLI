#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stm32f1xx_hal.h"
void set_led(uint8_t index,uint8_t sta);
void toggle_led(uint8_t index);
void set_all_led(uint8_t sta);
void led_driver_init(void);
#endif
