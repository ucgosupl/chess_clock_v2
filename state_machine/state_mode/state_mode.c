#include "state_mode.h"

#include <stdlib.h>

#include "mode/mode.h"
#include "display/display.h"

static enum mode mode;

void mode_on_entry(void)
{

}

enum state mode_on_tick(events_t events)
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
		return CONFIG;
	}
	else
	{

	}

	display_show_mode(mode);

	return MODE;
}

void mode_on_exit(void)
{
	mode_set(mode);
}
