#include "state_machine.h"

#include "state_mode/state_mode.h"
#include "state_config/state_config.h"
#include "state_game/state_game.h"
#include "state_edit/state_edit.h"

#include "periodic_tasks/periodic_tasks.h"
#include "buttons/buttons.h"

static enum state last_state;
static enum state new_state;
static enum state state = MODE;

typedef const struct state_interface * (*state_get_t)(void);

static const state_get_t states[STATE_MAX] = 
{
	state_mode_get,
	state_config_get,
	state_game_get,
	state_edit_get,
};

static void state_machine_tick(events_t events);

void state_machine_init(void)
{
	state = MODE;

	buttons_init();

	periodic_subscribe_100ms(state_machine_update);

	for (enum state i = 0; i < STATE_MAX; i++)
	{
		states[i]()->init();
	}
}

void state_machine_update(void)
{
	events_t events = events_update();
	state_machine_tick(events);
}

static void state_machine_tick(events_t events)
 {
	if (state != last_state)
	{
		states[state]()->on_entry();
	}

	new_state = states[state]()->on_tick(events);

	if (state != new_state)
	{
		states[state]()->on_exit();
	}

	last_state = state;
	state = new_state;
}
