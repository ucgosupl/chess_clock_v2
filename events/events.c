#include "events.h"

#include "buttons/buttons.h"

static events_t last_events = 0;
static uint32_t play_pressed_cnt = 0;
static const uint32_t PLAY_PRESSED_THRESHOLD = 3 * 10;

void events_init(void)
{
	last_events = 0;
	play_pressed_cnt = 0;
}

events_t events_update(void)
{
	events_t events = 0;

	if (buttons_is_plus_pressed())
	{
		if (!(EVENT_IS_ACTIVE(last_events, EVENT_BUTTON_PLUS)))
			EVENT_SET(events, EVENT_BUTTON_PLUS);
	}
	else if (buttons_is_minus_pressed())
	{
		if (!(EVENT_IS_ACTIVE(last_events, EVENT_BUTTON_MINUS)))
			EVENT_SET(events, EVENT_BUTTON_MINUS);
	}
	else if (buttons_is_left_pressed())
	{
		if (!(EVENT_IS_ACTIVE(last_events, EVENT_BUTTON_LEFT)))
			EVENT_SET(events, EVENT_BUTTON_LEFT);
	}
	else if (buttons_is_right_pressed())
	{
		if (!(EVENT_IS_ACTIVE(last_events, EVENT_BUTTON_RIGHT)))
			EVENT_SET(events, EVENT_BUTTON_RIGHT);
	}
	else if (buttons_is_play_pressed())
	{
		play_pressed_cnt++;
	}
	else
	{
		/* PLAY PRESS */
		if (play_pressed_cnt > 0)
		{
			EVENT_SET(events, EVENT_BUTTON_PLAY);
		}

		/* PLAY LONG PRESS */
		if (play_pressed_cnt > PLAY_PRESSED_THRESHOLD)
		{
			EVENT_SET(events, EVENT_BUTTON_EDIT);
		}

		play_pressed_cnt = 0;
	}

	last_events = events;

	return events;
}
