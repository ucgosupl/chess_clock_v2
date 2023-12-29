#include "game/mode_interface.h"

struct bonus_control_data
{
	ms_t time_p1;
	ms_t time_p2;

	ms_t inc_p1;
	ms_t inc_p2;

	moves_t moves_p1;
	moves_t moves_p2;

	moves_t control_on_move;
	ms_t bonus;
};

static struct bonus_control_data data;


static void bonus_control_on_start(void)
{
	//do nothing
}

static void bonus_control_on_time_update(enum turn whose_turn)
{
	if ((whose_turn == PLAYER1) && (data.time_p1 > 0))
		data.time_p1--;
	else if ((whose_turn == PLAYER2) && (data.time_p2 > 0))
		data.time_p2--;
	else {}
}

static void bonus_control_on_move(enum turn who_moved)
{
	if ((who_moved == PLAYER1) && (data.time_p1 > 0))
	{
		data.time_p1 += data.inc_p1;
		data.moves_p1++;
		if (data.moves_p1 == data.control_on_move)
		{
			data.time_p1 += data.bonus;
		}
	}

	if ((who_moved == PLAYER2) && (data.time_p2 > 0))
	{
		data.time_p2 += data.inc_p2;
		data.moves_p2++;
		if (data.moves_p2 == data.control_on_move)
		{
			data.time_p2 += data.bonus;
		}
	}
}

static ms_t bonus_control_time_get(enum state player)
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

static const struct mode_interface bonus_control_mode =
{
		bonus_control_on_start,
		bonus_control_on_time_update,
		bonus_control_on_move,
		bonus_control_time_get,
};

const struct mode_interface * bonus_control_init(ms_t time, ms_t inc, moves_t moves, ms_t bonus)
{
	data.time_p1 = time + inc;
	data.time_p2 = time + inc;

	data.inc_p1 = inc;
	data.inc_p2 = inc;

	data.moves_p1 = 0;
	data.moves_p2 = 0;

	data.control_on_move = moves;
	data.bonus = bonus;

	return &bonus_control_mode;
}
