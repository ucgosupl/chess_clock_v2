#include "state_mode.h"

#include <stdlib.h>

#include "mode/mode.h"
#include "display/display.h"

static enum mode mode;

void mode_on_entry(void)
{

}

uint32_t mode_on_tick(events_t events)
{
	if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLUS))
	{
		if (mode < MODES_MAX)
		{
			mode++;
		}
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_MINUS))
	{
		if (mode > 0)
		{
			mode--;
		}
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLAY))
	{
		//TODO: handle state properly
		return 1;
	}
	else
	{

	}

	display_show_mode(mode);

	return 0;
}

void mode_on_exit(void)
{

}

enum mode mode_get(void)
{
	return mode;
}
