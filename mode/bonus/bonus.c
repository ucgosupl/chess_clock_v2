#include "mode_bonus.h"

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

static void bonus_on_time_update(enum player whose_turn)
{
	if ((whose_turn == PLAYER1) && (data.time_p1 > 0))
		data.time_p1--;
	else if ((whose_turn == PLAYER2) && (data.time_p2 > 0))
		data.time_p2--;
	else {}
}

static void bonus_on_move(enum player who_moved)
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

static ms_t bonus_time_get(enum player player)
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

static moves_t bonus_moves_get(enum player player)
{
	(void) player;
	
	return 0;
}

static const struct game_controller bonus_mode =
{
		bonus_on_start,
		bonus_on_time_update,
		bonus_on_move,
		bonus_time_get,
		bonus_moves_get,
};

const struct game_controller * bonus_game_controller_get(void)
{
	return &bonus_mode;
}

static void bonus_init(void)
{

}

static void bonus_set_time(enum player p, ms_t t)
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

static void bonus_set_increment(enum player p, ms_t i)
{
	switch(p)
	{
		case PLAYER1:
			data.inc_p1 = i;
			data.time_p1 += i;
			break;
		case PLAYER2:
			data.inc_p2 = i;
			data.time_p2 += i;
			break;
		case PLAYER_BOTH:
			data.inc_p1 = i;
			data.time_p1 += i;

			data.inc_p2 = i;
			data.time_p2 += i;
			break;

		default:
			break;
	}
}

static void bonus_set_bonus(enum player p, ms_t b)
{
	(void) p;
	(void) b;
}

static void bonus_set_moves(enum player p, moves_t m)
{
	(void) p;
	(void) m;
}

static const struct mode_builder bonus_builder =
{
	bonus_init,
	bonus_set_time,
	bonus_set_increment,
	bonus_set_bonus,
	bonus_set_moves,
};

const struct mode_builder * bonus_mode_builder_get(void)
{
	return &bonus_builder;
}

static void bonus_edit_time(enum player p, ms_t t)
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

static void bonus_edit_moves(enum player p, moves_t m)
{
	(void) p;
	(void) m;
}

static const struct edit_builder bonus_edit_builder =
{
	bonus_edit_time,
	bonus_edit_moves,
};

const struct edit_builder * bonus_edit_builder_get(void)
{
	return &bonus_edit_builder;
}