#include "state_game.h"

#include <stdlib.h>

#include "display/display.h"
#include "buttons/buttons.h"
#include "mode/mode.h"
#include "turn/turn.h"
#include "periodic_tasks/periodic_tasks.h"

enum game_state {PAUSED, STARTED};

static enum state state;

static enum game_state game_state = PAUSED;
static const struct game_controller *game_mode = NULL;

static void game_on_move(enum player who_moved);
static void game_time_update(void);

static void game_on_move(enum player who_moved)
{
	if (STARTED == game_state)
	{
		game_mode->on_move(who_moved);
	}
}

static void game_init(void)
{
	periodic_subscribe_1ms(game_time_update);
}

static void game_on_entry(void)
{
	state = GAME;

	game_mode = mode_game_controller_get();

	game_state = PAUSED;
	turn_subscribe(game_on_move);
}

static enum state game_on_tick(events_t events)
{
	if (game_state == PAUSED && EVENT_IS_ACTIVE(events, EVENT_BUTTON_EDIT))
	{
		state = EDIT;
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLAY))
	{
		if (game_state == STARTED)
		{
			game_state = PAUSED;
		}
		else
		{
			game_state = STARTED;
			game_mode->on_start();
		}
	}

	display_show_time(game_mode->time_get(PLAYER1),game_mode->time_get(PLAYER2));

	return state;
}

static void game_on_exit(void)
{

}

static void game_time_update(void)
{
	if ((game_state == STARTED) && (game_mode != NULL))
	{
		game_mode->on_time_update(turn_get());
	}
}

static const struct state_interface state_game = 
{
	game_init,
	game_on_entry,
	game_on_tick,
	game_on_exit,
};

const struct state_interface * state_game_get(void)
{
	return &state_game;
}
