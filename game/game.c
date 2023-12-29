#include "game.h"
#include <stdlib.h>

#include "display/display.h"
#include "buttons/buttons.h"

static enum state game_state = NOT_STARTED;
static const struct mode_interface *game_mode = NULL;

static void game_move(enum state player);
static ms_t game_p1_time_get(void);
static ms_t game_p2_time_get(void);

void game_init(const struct mode_interface *mode)
{
	game_mode = mode;

	game_state = NOT_STARTED;
}

void game_start(void)
{
	game_state = P1;
	game_mode->on_start();
}

void game_on_tick(void)
{
	display_show_time(game_p1_time_get(), game_p2_time_get());

	switch (game_state)
	{
	case NOT_STARTED:
		break;
	case P1:
		if (buttons_is_p1_pressed())
			game_move(P2);
		break;
	case P2:
		if (buttons_is_p2_pressed())
			game_move(P1);
		break;
	default:
		break;
	}
}

void game_time_update(void)
{
	if (game_mode != NULL)
	{
		game_mode->on_time_update(game_state);
	}
}

static void game_move(enum state player)
{
	game_mode->on_move(player);
	game_state = player;
}

static ms_t game_p1_time_get(void)
{
	return game_mode->time_get(P1);
}

static ms_t game_p2_time_get(void)
{
	return game_mode->time_get(P2);
}
