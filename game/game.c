#include "game.h"
#include <stdlib.h>

//static volatile ms_t time_p1;
//static volatile ms_t time_p2;

//static ms_t inc_p1;
//static ms_t inc_p2;

static enum state game_state = NOT_STARTED;
static const struct mode_interface *game_mode = NULL;



void game_init(const struct mode_interface *mode)
{
//	time_p1 = time + inc;
//	time_p2 = time + inc;
//
//	inc_p1 = inc;
//	inc_p2 = inc;
	game_mode = mode;

	game_state = NOT_STARTED;
}

void game_start(void)
{
	game_state = P1;
	game_mode->on_start();
}

void game_move(enum state player)
{
//	if (player == P2 && time_p1 > 0)
//	{
//		time_p1 += inc_p1;
//	}
//
//	if (player == P1 && time_p2 > 0)
//	{
//		time_p2 += inc_p2;
//	}

	game_mode->on_move(player);
	game_state = player;
}

enum state game_state_get(void)
{
	return game_state;
}

void game_time_update(void)
{
//	if (game_state == P1 && time_p1 > 0)
//		time_p1--;
//	else if (game_state == P2 && time_p2 > 0)
//		time_p2--;
//	else {}
	if (game_mode != NULL)
	{
		game_mode->on_time_update(game_state);
	}
}

ms_t game_p1_time_get(void)
{
	return game_mode->time_get(P1);
}

ms_t game_p2_time_get(void)
{
	return game_mode->time_get(P2);
}
