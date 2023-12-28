#include "config.h"

#include "display/display.h"
#include "buttons/buttons.h"

enum config_state
{
	P1_HOURS,
	P1_MIN1,
	P1_MIN2,
	P1_SEC1,
	P1_SEC2,

	P2_HOURS,
	P2_MIN1,
	P2_MIN2,
	P2_SEC1,
	P2_SEC2,

	CONFIG_DONE,
};

enum config_state config_state = P1_HOURS;
ms_t config_time_p1 = 0;
ms_t config_time_p2 = 0;

void config_on_tick(void)
{
	if (buttons_is_plus_pressed())
	{
		switch (config_state)
		{
		case P1_HOURS:
			config_time_p1 += TIME_TO_MS(1, 0, 0);
			break;
		case P1_MIN1:
			config_time_p1 += TIME_TO_MS(0, 10, 0);
			break;
		case P1_MIN2:
			config_time_p1 += TIME_TO_MS(0, 1, 0);
			break;
		case P1_SEC1:
			config_time_p1 += TIME_TO_MS(0, 0, 10);
			break;
		case P1_SEC2:
			config_time_p1 += TIME_TO_MS(0, 0, 1);
			break;

		case P2_HOURS:
			config_time_p2 += TIME_TO_MS(1, 0, 0);
			break;
		case P2_MIN1:
			config_time_p2 += TIME_TO_MS(0, 10, 0);
			break;
		case P2_MIN2:
			config_time_p2 += TIME_TO_MS(0, 1, 0);
			break;
		case P2_SEC1:
			config_time_p2 += TIME_TO_MS(0, 0, 10);
			break;
		case P2_SEC2:
			config_time_p2 += TIME_TO_MS(0, 0, 1);
			break;

		default:
			break;
		}
	}
	else if (buttons_is_minus_pressed())
	{
		switch (config_state)
		{
		case P1_HOURS:
			config_time_p1 -= TIME_TO_MS(1, 0, 0);
			break;
		case P1_MIN1:
			config_time_p1 -= TIME_TO_MS(0, 10, 0);
			break;
		case P1_MIN2:
			config_time_p1 -= TIME_TO_MS(0, 1, 0);
			break;
		case P1_SEC1:
			config_time_p1 -= TIME_TO_MS(0, 0, 10);
			break;
		case P1_SEC2:
			config_time_p1 -= TIME_TO_MS(0, 0, 1);
			break;

		case P2_HOURS:
			config_time_p2 -= TIME_TO_MS(1, 0, 0);
			break;
		case P2_MIN1:
			config_time_p2 -= TIME_TO_MS(0, 10, 0);
			break;
		case P2_MIN2:
			config_time_p2 -= TIME_TO_MS(0, 1, 0);
			break;
		case P2_SEC1:
			config_time_p2 -= TIME_TO_MS(0, 0, 10);
			break;
		case P2_SEC2:
			config_time_p2 -= TIME_TO_MS(0, 0, 1);
			break;

		default:
			break;
		}
	}
	else if (buttons_is_left_pressed())
	{
		if (P1_HOURS < config_state)
		{
			config_state--;
		}
	}
	else if (buttons_is_right_pressed())
	{
		if (CONFIG_DONE > config_state)
		{
			config_state++;
		}
	}
	else if (buttons_is_play_pressed())
	{

	}
	else
	{

	}

	display_show_config_time(config_time_p1, config_time_p2, config_state);
}
