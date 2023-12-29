#include "state_game.h"

#include <stdlib.h>

#include "display/display.h"
#include "buttons/buttons.h"
#include "mode/mode.h"

enum state {NOT_STARTED, STARTED, PAUSED};

static enum state game_state = NOT_STARTED;
static const struct mode_interface *game_mode = NULL;

static void game_on_move(enum turn who_moved);
static ms_t game_p1_time_get(void);
static ms_t game_p2_time_get(void);

static void game_on_move(enum turn who_moved)
{
	if (STARTED == game_state)
	{
		game_mode->on_move(who_moved);
	}
}

void game_on_entry(void)
{
	game_mode = mode_interface_get();

	game_state = NOT_STARTED;
	turn_subscribe(game_on_move);
}

void game_on_tick(events_t events)
{
	if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLAY))
	{
		if (game_state == STARTED)
		{
			game_state = PAUSED;
		}
		else
		{
			game_state = STARTED;
			//game_mode->on_start();
		}
	}

	display_show_time(game_p1_time_get(), game_p2_time_get());
}

void game_on_exit(void)
{

}

void game_time_update(void)
{
	if ((game_state == STARTED) && (game_mode != NULL))
	{
		game_mode->on_time_update(turn_get());
	}
}

static ms_t game_p1_time_get(void)
{
	return game_mode->time_get(PLAYER1);
}

static ms_t game_p2_time_get(void)
{
	return game_mode->time_get(PLAYER2);
}
