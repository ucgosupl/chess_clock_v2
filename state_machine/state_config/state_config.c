#include "state_config.h"

#include "config/config.h"

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
		break;

	default:
		config = config_fixed_get();
		break;
	}


	config->on_entry(completed_cb);
}

uint32_t config_on_tick(events_t events)
{
	if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLUS))
	{
		config->on_plus();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_MINUS))
	{
		config->on_minus();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_LEFT))
	{
		config->on_left();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_RIGHT))
	{
		config->on_right();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLAY))
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
