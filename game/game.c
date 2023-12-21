#include "game.h"

static volatile uint32_t time_p1;
static volatile uint32_t time_p2;

static enum state game_state = NOT_STARTED;

void game_init(uint32_t time)
{
	time_p1 = time;
	time_p2 = time;

	game_state = NOT_STARTED;
}

void game_start(void)
{
	game_state = P1;
}

void game_move(enum state player)
{
	game_state = player;
}

enum state game_state_get(void)
{
	return game_state;
}

void game_time_update(void)
{
	if (game_state == P1 && time_p1 > 0)
		time_p1--;
	else if (game_state == P2 && time_p2 > 0)
		time_p2--;
	else {}
}

uint32_t game_p1_time_get(void)
{
	return time_p1;
}

uint32_t game_p2_time_get(void)
{
	return time_p2;
}
