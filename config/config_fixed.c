#include "config.h"

#include <stdlib.h>

#include "display/display.h"
#include "game/game.h"

static enum config_state state;

static struct config_time p1_time;
static struct config_time p2_time;

static config_completed_cb_t completed_cb = NULL;

static void fixed_on_entry(config_completed_cb_t cb)
{
	completed_cb = cb;
}

static void fixed_on_exit(void)
{
	game_init(fixed_init(TIME_TO_MS(p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2)));
}

static void fixed_on_plus(void)
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

	default:
		break;
	}
}

static void fixed_on_minus(void)
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

	default:
		break;
	}
}

static void fixed_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void fixed_on_right(void)
{
	if (P2_SEC2 > state)
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

static void fixed_display(void)
{
	display_show_config_time(&p1_time, &p2_time, state);
}

static const struct config_interface config_fixed =
{
		fixed_on_entry,
		fixed_on_exit,
		fixed_on_plus,
		fixed_on_minus,
		fixed_on_left,
		fixed_on_right,
		fixed_display,
};

const struct config_interface * config_fixed_get(void)
{
	return &config_fixed;
}
