#include "state_mode.h"

#include <stdlib.h>

#include "mode/mode.h"
#include "display/display.h"

static enum mode mode;

static void mode_init(void)
{

}

static void mode_on_entry(void)
{

}

static enum state mode_on_tick(events_t events)
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

static void mode_on_exit(void)
{
	mode_set(mode);
}

static const struct state_interface state_mode = 
{
	mode_init,
	mode_on_entry,
	mode_on_tick,
	mode_on_exit,
};

const struct state_interface * state_mode_get(void)
{
	return &state_mode;
}