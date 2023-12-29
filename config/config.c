#include "config.h"

#include "buttons/buttons.h"

static uint32_t state;

const struct config_interface *config;

static void completed_cb(void)
{
	state = 2;
}

void config_on_entry(enum mode mode)
{
	state = 1;

	switch (mode)
	{
	case FIXED_CUSTOM:
		config = config_fixed_get();
		break;

	case BONUS_CUSTOM:
		config = config_bonus_get();
		break;

	case BONUSC_CUSTOM:
		config = config_bonus_control_get();

	default:
		break;
	}


	config->on_entry(completed_cb);
}

uint32_t config_on_tick(void)
{
	if (buttons_is_plus_pressed())
	{
		config->on_plus();
	}
	else if (buttons_is_minus_pressed())
	{
		config->on_minus();
	}
	else if (buttons_is_left_pressed())
	{
		config->on_left();
	}
	else if (buttons_is_right_pressed())
	{
		config->on_right();
	}
	else if (buttons_is_play_pressed())
	{

	}
	else
	{

	}

	config->display();

	return state;
}

void config_on_exit(void)
{
	config->on_exit();
}
