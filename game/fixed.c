#include "mode_interface.h"

struct fixed_data
{
	ms_t time_p1;
	ms_t time_p2;
};

static struct fixed_data f;


static void fixed_on_start(void)
{
	//do nothing
}

static void fixed_on_time_update(enum state game_state)
{
	if (game_state == P1 && f.time_p1 > 0)
		f.time_p1--;
	else if (game_state == P2 && f.time_p2 > 0)
		f.time_p2--;
	else {}
}

static void fixed_on_move(enum state game_state)
{
	//do nothing
}

static ms_t fixed_time_get(enum state game_state)
{
	switch (game_state)
	{
	case P1:
		return f.time_p1;
	case P2:
		return f.time_p2;
	default:
		return 0;
	}
}

static const struct mode_interface fixed_mode =
{
		fixed_on_start,
		fixed_on_time_update,
		fixed_on_move,
		fixed_time_get,
};

const struct mode_interface * fixed_init(ms_t time)
{
	f.time_p1 = time;
	f.time_p2 = time;

	return &fixed_mode;
}
