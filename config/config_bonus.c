#include "config.h"

#include "display/display.h"
#include "game/game.h"

static enum config_state state;

static struct config_time p1_time;
static struct config_time p2_time;
static struct config_time p1_inc;
static struct config_time p2_inc;

static config_completed_cb completed_cb = NULL;

static void bonus_on_entry(config_completed_cb cb)
{
	completed_cb = cb;
}

static void bonus_on_exit(void)
{
	game_init(bonus_init(TIME_TO_MS(
			p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2),
			TIME_TO_MS(
					0, p1_inc.m1*10 + p1_inc.m2, p1_inc.s1*10 + p1_inc.s2)));
}

static void bonus_on_plus(void)
{
	switch (state)
	{
	case P1_HOURS:
		p1_time.h = add_with_bounds(p1_time.h);
		break;
	case P1_MIN1:
		p1_time.m1 = add_with_bounds(p1_time.m1);
		break;
	case P1_MIN2:
		p1_time.m2 = add_with_bounds(p1_time.m2);
		break;
	case P1_SEC1:
		p1_time.s1 = add_with_bounds(p1_time.s1);
		break;
	case P1_SEC2:
		p1_time.s2 = add_with_bounds(p1_time.s2);
		break;

	case P2_HOURS:
		p2_time.h = add_with_bounds(p2_time.h);
		break;
	case P2_MIN1:
		p2_time.m1 = add_with_bounds(p2_time.m1);
		break;
	case P2_MIN2:
		p2_time.m2 = add_with_bounds(p2_time.m2);
		break;
	case P2_SEC1:
		p2_time.s1 = add_with_bounds(p2_time.s1);
		break;
	case P2_SEC2:
		p2_time.s2 = add_with_bounds(p2_time.s2);
		break;

	case P1_INC_MIN:
		p1_inc.m2 = add_with_bounds(p1_inc.m2);
		break;
	case P1_INC_SEC1:
		p1_inc.s1 = add_with_bounds(p1_inc.s1);
		break;
	case P1_INC_SEC2:
		p1_inc.s2 = add_with_bounds(p1_inc.s2);
		break;

	case P2_INC_MIN:
		p2_inc.m2 = add_with_bounds(p2_inc.m2);
		break;
	case P2_INC_SEC1:
		p2_inc.s1 = add_with_bounds(p2_inc.s1);
		break;
	case P2_INC_SEC2:
		p2_inc.s2 = add_with_bounds(p2_inc.s2);
		break;

	default:
		break;
	}
}

static void bonus_on_minus(void)
{
	switch (state)
	{
	case P1_HOURS:
		p1_time.h = sub_with_bounds(p1_time.h);
		break;
	case P1_MIN1:
		p1_time.m1 = sub_with_bounds(p1_time.m1);
		break;
	case P1_MIN2:
		p1_time.m2 = sub_with_bounds(p1_time.m2);
		break;
	case P1_SEC1:
		p1_time.s1 = sub_with_bounds(p1_time.s1);
		break;
	case P1_SEC2:
		p1_time.s2 = sub_with_bounds(p1_time.s2);
		break;

	case P2_HOURS:
		p2_time.h = sub_with_bounds(p2_time.h);
		break;
	case P2_MIN1:
		p2_time.m1 = sub_with_bounds(p2_time.m1);
		break;
	case P2_MIN2:
		p2_time.m2 = sub_with_bounds(p2_time.m2);
		break;
	case P2_SEC1:
		p2_time.s1 = sub_with_bounds(p2_time.s1);
		break;
	case P2_SEC2:
		p2_time.s2 = sub_with_bounds(p2_time.s2);
		break;

	case P1_INC_MIN:
		p1_inc.m2 = sub_with_bounds(p1_inc.m2);
		break;
	case P1_INC_SEC1:
		p1_inc.s1 = sub_with_bounds(p1_inc.s1);
		break;
	case P1_INC_SEC2:
		p1_inc.s2 = sub_with_bounds(p1_inc.s2);
		break;

	case P2_INC_MIN:
		p2_inc.m2 = sub_with_bounds(p2_inc.m2);
		break;
	case P2_INC_SEC1:
		p2_inc.s1 = sub_with_bounds(p2_inc.s1);
		break;
	case P2_INC_SEC2:
		p2_inc.s2 = sub_with_bounds(p2_inc.s2);
		break;

	default:
		break;
	}
}

static void bonus_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void bonus_on_right(void)
{
	if (P2_INC_SEC2 > state)
	{
		state++;
	}
	else
	{
		state = CONFIG_DONE;
		if (NULL != completed_cb)
		{
			completed_cb();
		}
	}
}

static void bonus_display(void)
{
	if (state < P1_INC_MIN)
	{
		display_show_config_time(&p1_time, &p2_time, state);
	}
	else if (state < MOVES1)
	{
		display_show_config_inc(&p1_inc, &p2_inc, state);
	}
}

static const struct config_interface config_bonus =
{
		bonus_on_entry,
		bonus_on_exit,
		bonus_on_plus,
		bonus_on_minus,
		bonus_on_left,
		bonus_on_right,
		bonus_display,
};

const struct config_interface * config_bonus_get(void)
{
	return &config_bonus;
}
