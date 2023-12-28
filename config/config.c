#include "config.h"

#include "buttons/buttons.h"

void config_on_tick(void)
{
	if (buttons_is_plus_pressed())
	{
		bonus_control_on_plus();
	}
	else if (buttons_is_minus_pressed())
	{
		bonus_control_on_minus();
	}
	else if (buttons_is_left_pressed())
	{
		bonus_control_on_left();
	}
	else if (buttons_is_right_pressed())
	{
		bonus_control_on_right();
	}
	else if (buttons_is_play_pressed())
	{

	}
	else
	{

	}

	bonus_control_display();
}
