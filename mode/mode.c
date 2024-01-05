#include "mode.h"

#include <stdlib.h>

#include "fixed/mode_fixed.h"
#include "fixed_control/mode_fixed_control.h"
#include "bonus/mode_bonus.h"
#include "bonus_control/mode_bonus_control.h"

static enum mode mode;

void mode_set(enum mode m)
{
	mode = m;
}

const struct config_controller * mode_config_controller_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return fixed_config_controller_get();

		case BONUS_CUSTOM:
			return bonus_config_controller_get();

		case BONUSC_CUSTOM:
			return bonus_control_config_controller_get();

		case FIXEDC_CUSTOM:
			return fixed_control_config_controller_get();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}

const struct mode_builder * mode_builder_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return fixed_mode_builder_get();

		case BONUS_CUSTOM:
			return bonus_mode_builder_get();

		case BONUSC_CUSTOM:
			return bonus_control_mode_builder_get();

		case FIXEDC_CUSTOM:
			return fixed_control_mode_builder_get();
			
		default:
			//TODO: handle errors
			return NULL;
	}
}

const struct game_controller *mode_game_controller_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return fixed_game_controller_get();

		case BONUS_CUSTOM:
			return bonus_game_controller_get();

		case BONUSC_CUSTOM:
			return bonus_control_game_controller_get();
		
		case FIXEDC_CUSTOM:
			return fixed_control_game_controller_get();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}
