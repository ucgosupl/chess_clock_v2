#include "mode_interface.h"

struct bonus_data
{
	ms_t time_p1;
	ms_t time_p2;

	ms_t inc_p1;
	ms_t inc_p2;
};

static struct bonus_data data;


static void bonus_on_start(void)
{
	//do nothing
}

static void bonus_on_time_update(enum state game_state)
{
	if (game_state == P1 && data.time_p1 > 0)
		data.time_p1--;
	else if (game_state == P2 && data.time_p2 > 0)
		data.time_p2--;
	else {}
}

static void bonus_on_move(enum state player)
{
	if (player == P2 && data.time_p1 > 0)
	{
		data.time_p1 += data.inc_p1;
	}

	if (player == P1 && data.time_p2 > 0)
	{
		data.time_p2 += data.inc_p2;
	}
}

static ms_t bonus_time_get(enum state player)
{
	switch (player)
	{
	case P1:
		return data.time_p1;
	case P2:
		return data.time_p2;
	default:
		return 0;
	}
}

static const struct mode_interface bonus_mode =
{
		bonus_on_start,
		bonus_on_time_update,
		bonus_on_move,
		bonus_time_get,
};

const struct mode_interface * bonus_init(ms_t time, ms_t inc)
{
	data.time_p1 = time + inc;
	data.time_p2 = time + inc;

	data.inc_p1 = inc;
	data.inc_p2 = inc;

	return &bonus_mode;
}
