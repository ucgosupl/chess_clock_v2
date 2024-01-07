#include "mode_bonus_control.h"

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

static void bonus_control_on_time_update(enum player whose_turn)
{
	if ((whose_turn == PLAYER1) && (data.time_p1 > 0))
		data.time_p1--;
	else if ((whose_turn == PLAYER2) && (data.time_p2 > 0))
		data.time_p2--;
	else {}
}

static void bonus_control_on_move(enum player who_moved)
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

static ms_t bonus_control_time_get(enum player player)
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

static moves_t bonus_control_moves_get(enum player player)
{
	switch(player)
	{
		case PLAYER1:
			return data.moves_p1;

		case PLAYER2:
			return data.moves_p2;

		default:
			break;
	}

	return 0;
}

static const struct game_controller bonus_control_mode =
{
		bonus_control_on_start,
		bonus_control_on_time_update,
		bonus_control_on_move,
		bonus_control_time_get,
		bonus_control_moves_get,
};

const struct game_controller * bonus_control_game_controller_get(void)
{
	return &bonus_control_mode;
}

static void bonus_control_init(void)
{
	data.moves_p1 = 0;
	data.moves_p2 = 0;
}

static void bonus_control_set_time(enum player p, ms_t t)
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

static void bonus_control_set_increment(enum player p, ms_t i)
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

static void bonus_control_set_bonus(enum player p, ms_t b)
{
	switch(p)
	{
		case PLAYER1:
			data.bonus = b;
			break;
		case PLAYER2:
			data.bonus = b;
			break;
		case PLAYER_BOTH:
			data.bonus = b;
			data.bonus = b;
			break;

		default:
			break;
	}
}

static void bonus_control_set_moves(enum player p, moves_t m)
{
	switch(p)
	{
		case PLAYER1:
			data.control_on_move = m;
			break;
		case PLAYER2:
			data.control_on_move = m;
			break;
		case PLAYER_BOTH:
			data.control_on_move = m;
			data.control_on_move = m;
			break;

		default:
			break;
	}	
}

static const struct mode_builder bonus_control_builder =
{
	bonus_control_init,
	bonus_control_set_time,
	bonus_control_set_increment,
	bonus_control_set_bonus,
	bonus_control_set_moves,
};

const struct mode_builder * bonus_control_mode_builder_get(void)
{
	return &bonus_control_builder;
}

static void bonus_control_edit_time(enum player p, ms_t t)
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

static void bonus_control_edit_moves(enum player p, moves_t m)
{
	switch(p)
	{
		case PLAYER1:
			data.moves_p1 = m;
			break;
		case PLAYER2:
			data.moves_p2 = m;
			break;
		case PLAYER_BOTH:
			data.moves_p1 = m;
			data.moves_p2 = m;
			break;

		default:
			break;
	}
}

static const struct edit_builder bonus_control_edit_builder =
{
	bonus_control_edit_time,
	bonus_control_edit_moves,
};

const struct edit_builder * bonus_control_edit_builder_get(void)
{
	return &bonus_control_edit_builder;
}
