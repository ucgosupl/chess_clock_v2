#include "state_config.h"

#include "mode/mode.h"

static enum state state;

static const struct config_controller *config;

static void completed_cb(void)
{
	state = GAME;
}

static void config_init(void)
{
	
}

static void config_on_entry(void)
{
	state = CONFIG;

	config = mode_config_controller_get();

	config->on_entry(completed_cb);
}

static enum state config_on_tick(events_t events)
{
	if (state != CONFIG)
	{
		return state;
	}
	
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

static void config_on_exit(void)
{
	config->on_exit();
}

static const struct state_interface state_config = 
{
	config_init,
	config_on_entry,
	config_on_tick,
	config_on_exit,
};

const struct state_interface * state_config_get(void)
{
	return &state_config;
}