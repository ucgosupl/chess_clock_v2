#include "mode_interface.h"
#include "mode_builder.h"

struct fixed_data
{
	ms_t time_p1;
	ms_t time_p2;
};

static struct fixed_data data;


static void fixed_on_start(void)
{
	//do nothing
}

static void fixed_on_time_update(enum player whose_turn)
{
	if ((whose_turn == PLAYER1) && (data.time_p1 > 0))
		data.time_p1--;
	else if ((whose_turn == PLAYER2) && (data.time_p2 > 0))
		data.time_p2--;
	else {}
}

static void fixed_on_move(enum player who_moved)
{
	//do nothing
}

static ms_t fixed_time_get(enum player player)
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

static const struct mode_interface fixed_mode =
{
		fixed_on_start,
		fixed_on_time_update,
		fixed_on_move,
		fixed_time_get,
};

const struct mode_interface * fixed_interface_get(void)
{
	return &fixed_mode;
}

static void fixed_init(void)
{

}

static void fixed_set_time(enum player p, ms_t t)
{
	switch(p)
	{
		case PLAYER1:
			data.time_p1 = t;
			break;
		case PLAYER2:
			data.time_p2 = t;
			break;
		case PLAYER_BOTH:
			data.time_p1 = t;
			data.time_p2 = t;
			break;

		default:
			break;
	}
}

static void fixed_set_increment(enum player p, ms_t i)
{
	(void) p;
	(void) i;
}

static void fixed_set_bonus(enum player p, ms_t b)
{
	(void) p;
	(void) b;
}

static void fixed_set_moves(enum player p, moves_t m)
{
	(void) p;
	(void) m;
}

static const struct mode_builder fixed_builder =
{
	fixed_init,
	fixed_set_time,
	fixed_set_increment,
	fixed_set_bonus,
	fixed_set_moves,
};

const struct mode_builder * fixed_builder_get(void)
{
	return &fixed_builder;
}
