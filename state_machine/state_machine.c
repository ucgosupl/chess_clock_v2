#include <state_machine/state_game/state_game.h>
#include "state_machine.h"

#include "state_mode/state_mode.h"
#include "state_config/state_config.h"
#include "periodic_tasks/periodic_tasks.h"

enum clock_state {MODE, CONFIG, GAME};

static enum clock_state last_state;
static enum clock_state new_state;
static enum clock_state state = MODE;

static void state_machine_tick(events_t events);

void state_machine_init(void)
{
	state = MODE;

	buttons_init();

	periodic_subscribe_100ms(state_machine_update);
	periodic_subscribe_1ms(game_time_update);
}

void state_machine_update(void)
{
	events_t events = events_update();
	state_machine_tick(events);
}

static void state_machine_tick(events_t events)
 {
	switch (state)
	{
	case MODE:
		new_state = mode_on_tick(events);

		if (MODE != new_state)
		{
			mode_on_exit();
		}
		break;

	case CONFIG:
		if (CONFIG != last_state)
		{
			config_on_entry(mode_get());
		}

		new_state = config_on_tick(events);

		if (CONFIG != new_state)
		{
			config_on_exit();
		}
		break;

	case GAME:
		if (GAME != last_state)
		{
			game_on_entry();
		}

		game_on_tick(events);

		if (GAME != new_state)
		{
			game_on_exit();
		}
		break;

	default:
		break;
	}

	last_state = state;
	state = new_state;
}
