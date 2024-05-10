#include "cli_command_table.h"
#include "cli_types.h"
#include "stm32f1xx_hal.h"
#include "effect_led_ci.h"



const cli_command_info_t command_infor_setEffectLed  =
{
	set_effect_led,
	"set effect of led"
};

const cli_command_entry_t command_entry_table[] =
{
	
	{"setEffectLed",&command_infor_setEffectLed},
	{NULL,NULL}
};
