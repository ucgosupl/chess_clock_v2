#include "events.h"

events_t events_update(void)
{
	events_t events = 0;

	if (buttons_is_plus_pressed())
	{
		EVENT_SET(events, EVENT_BUTTON_PLUS);
	}
	else if (buttons_is_minus_pressed())
	{
		EVENT_SET(events, EVENT_BUTTON_MINUS);
	}
	else if (buttons_is_left_pressed())
	{
		EVENT_SET(events, EVENT_BUTTON_LEFT);
	}
	else if (buttons_is_right_pressed())
	{
		EVENT_SET(events, EVENT_BUTTON_RIGHT);
	}
	else if (buttons_is_play_pressed())
	{
		EVENT_SET(events, EVENT_BUTTON_PLAY);
	}
	else
	{

	}

	return events;
}
