#include "mode_interface.h"

struct fixed_control_data
{
	ms_t time_p1;
	ms_t time_p2;

	moves_t moves_p1;
	moves_t moves_p2;

	moves_t control_on_move;
	ms_t bonus;
};

static struct fixed_control_data data;


static void fixed_control_on_start(void)
{
	//do nothing
}

static void fixed_control_on_time_update(enum state game_state)
{
	if (game_state == P1 && data.time_p1 > 0)
		data.time_p1--;
	else if (game_state == P2 && data.time_p2 > 0)
		data.time_p2--;
	else {}
}

static void fixed_control_on_move(enum state player)
{
	if (player == P2 && data.time_p1 > 0)
	{
		data.moves_p1++;
		if (data.moves_p1 == data.control_on_move)
		{
			data.time_p1 += data.bonus;
		}
	}

	if (player == P1 && data.time_p2 > 0)
	{
		data.moves_p2++;
		if (data.moves_p2 == data.control_on_move)
		{
			data.time_p2 += data.bonus;
		}
	}
}

static ms_t fixed_control_time_get(enum state player)
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

static const struct mode_interface fixed_control_mode =
{
		fixed_control_on_start,
		fixed_control_on_time_update,
		fixed_control_on_move,
		fixed_control_time_get,
};

const struct mode_interface * fixed_control_init(ms_t time, moves_t moves, ms_t bonus)
{
	data.time_p1 = time;
	data.time_p2 = time;

	data.moves_p1 = 0;
	data.moves_p2 = 0;

	data.control_on_move = moves;
	data.bonus = bonus;

	return &fixed_control_mode;
}
