#include "mode.h"

#include <stdlib.h>

static enum mode mode;

void mode_set(enum mode m)
{
	mode = m;
}

const struct config_interface * mode_config_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return config_fixed_get();

		case BONUS_CUSTOM:
			return config_bonus_get();

		case BONUSC_CUSTOM:
			return config_bonus_control_get();
		
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
			return fixed_builder_get();

		case BONUS_CUSTOM:
			return bonus_builder_get();

		case BONUSC_CUSTOM:
			return bonus_control_builder_get();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}

const struct mode_interface *mode_interface_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return fixed_interface_get();

		case BONUS_CUSTOM:
			return bonus_interface_get();

		case BONUSC_CUSTOM:
			return bonus_control_interface_get();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}
