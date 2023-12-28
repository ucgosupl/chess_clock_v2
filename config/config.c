#include "config.h"

#include "buttons/buttons.h"

static uint32_t state;

static void completed_cb(void)
{
	state = 2;
}

void config_on_entry(uint32_t mode)
{
	state = 1;
	config_fixed_on_entry(completed_cb);
}

uint32_t config_on_tick(void)
{
	if (buttons_is_plus_pressed())
	{
		fixed_on_plus();
	}
	else if (buttons_is_minus_pressed())
	{
		fixed_on_minus();
	}
	else if (buttons_is_left_pressed())
	{
		fixed_on_left();
	}
	else if (buttons_is_right_pressed())
	{
		fixed_on_right();
	}
	else if (buttons_is_play_pressed())
	{

	}
	else
	{

	}

	fixed_display();

	return state;
}

void config_on_exit(void)
{
	config_fixed_on_exit();
}
