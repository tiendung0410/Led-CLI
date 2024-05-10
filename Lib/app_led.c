#include "app_led.h"
#include "led_driver.h"

typedef enum
{
	LED_IDLE_STATE,
	LED_BLINK_STATE,
	LED_LIGHT_UP_STATE
}LED_STATE_NAME;

typedef struct
{
	LED_STATE_NAME led_state_name;
	uint32_t time;
	uint32_t tick;
	
	union
	{
		struct
		{
			uint8_t sta;
		}blink;
		
		struct
		{
			int8_t index;
			int8_t direct;
		}light_up;
		
	}effect;
	
}AppLedState;

static AppLedState app_led_state;
void app_led_excute()
{
	switch(app_led_state.led_state_name)
	{
		case LED_BLINK_STATE:
			app_led_state.effect.blink.sta = !app_led_state.effect.blink.sta;
			set_all_led(app_led_state.effect.blink.sta );
			break;
		case LED_LIGHT_UP_STATE:
			
		set_led(app_led_state.effect.light_up.index,app_led_state.effect.light_up.direct==1?1:0);
		
		 app_led_state.effect.light_up.index += app_led_state.effect.light_up.direct;
		
		 if(app_led_state.effect.light_up.index > 7 )
		 {
			 app_led_state.effect.light_up.direct = -1;
		 }
		 if(app_led_state.effect.light_up.index < 0)
		 {
			  app_led_state.effect.light_up.direct = 1;
		 }
		 
		default:
			
			break;
	}
}
void app_led_handle()
{
	if(app_led_state.led_state_name != LED_IDLE_STATE)
	{
		if(HAL_GetTick() - app_led_state.tick >= app_led_state.time)
		{
			app_led_excute();
			app_led_state.tick = HAL_GetTick();
		}
	}
}
//sang dan
void app_led_light_up(uint16_t freq)
{
	app_led_state.led_state_name = LED_LIGHT_UP_STATE;
	app_led_state.time = freq;
	app_led_state.effect.light_up.index =0;
	app_led_state.effect.light_up.direct =1;
}
void app_led_blink_all(uint16_t freq)
{
	app_led_state.led_state_name = LED_BLINK_STATE;
	app_led_state.time = freq;
}
void app_led_init(void)
{
	app_led_state.led_state_name = LED_IDLE_STATE;
	led_driver_init();
}
