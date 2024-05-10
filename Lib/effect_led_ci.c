#include "effect_led_ci.h"
#include "response_ci.h"
#include <stdlib.h>
#include "app_led.h"

void set_effect_led(char **argv,uint8_t arg_num)
{
	uint8_t index_effect = atoi(argv[1]);
	if(index_effect ==1)
	{
		uint16_t freq = atoi(argv[2]);
		app_led_blink_all(freq);
		response_print("Effect 1 has been set");
	}
	if(index_effect ==2)
	{
		uint16_t freq = atoi(argv[2]);
		app_led_light_up(freq);
		response_print("Effect 2 has been set");
	}
}

