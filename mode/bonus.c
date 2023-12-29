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

static void bonus_on_time_update(enum turn whose_turn)
{
	if ((whose_turn == PLAYER1) && (data.time_p1 > 0))
		data.time_p1--;
	else if ((whose_turn == PLAYER2) && (data.time_p2 > 0))
		data.time_p2--;
	else {}
}

static void bonus_on_move(enum turn who_moved)
{
	if ((who_moved == PLAYER1) && (data.time_p1 > 0))
	{
		data.time_p1 += data.inc_p1;
	}

	if ((who_moved == PLAYER2) && (data.time_p2 > 0))
	{
		data.time_p2 += data.inc_p2;
	}
}

static ms_t bonus_time_get(enum turn player)
{
	switch (player)
	{
	case PLAYER1:
		return data.time_p1;
	case PLAYER2:
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

void bonus_init(ms_t time, ms_t inc)
{
	data.time_p1 = time + inc;
	data.time_p2 = time + inc;

	data.inc_p1 = inc;
	data.inc_p2 = inc;
}

const struct mode_interface * bonus_interface_get(void)
{

}
