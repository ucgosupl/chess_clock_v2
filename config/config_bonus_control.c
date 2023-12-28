#include "config.h"

#include "display/display.h"

static enum config_state state;

static struct config_time p1_time;
static struct config_time p2_time;
static struct config_time p1_inc;
static struct config_time p2_inc;
static struct config_time bonus;

static uint32_t moves = 0;

void bonus_control_on_plus(void)
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

	case MOVES1:
		moves += 10;
		break;
	case MOVES2:
		moves += 1;
		break;

	case BONUS_HOURS:
		bonus.h = add_with_bounds(bonus.h);
		break;
	case BONUS_MIN1:
		bonus.m1 = add_with_bounds(bonus.m1);
		break;
	case BONUS_MIN2:
		bonus.m2 = add_with_bounds(bonus.m2);
		break;
	case BONUS_SEC1:
		bonus.s1 = add_with_bounds(bonus.s1);
		break;
	case BONUS_SEC2:
		bonus.s2 = add_with_bounds(bonus.s2);
		break;

	default:
		break;
	}
}

void bonus_control_on_minus(void)
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

	case MOVES1:
		moves -= 10;
		break;
	case MOVES2:
		moves -= 1;
		break;

	case BONUS_HOURS:
		bonus.h = sub_with_bounds(bonus.h);
		break;
	case BONUS_MIN1:
		bonus.m1 = sub_with_bounds(bonus.m1);
		break;
	case BONUS_MIN2:
		bonus.m2 = sub_with_bounds(bonus.m2);
		break;
	case BONUS_SEC1:
		bonus.s1 = sub_with_bounds(bonus.s1);
		break;
	case BONUS_SEC2:
		bonus.s2 = sub_with_bounds(bonus.s2);
		break;

	default:
		break;
	}
}

void bonus_control_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

void bonus_control_on_right(void)
{
	if (CONFIG_DONE > state)
	{
		state++;
	}

}

void bonus_control_display(void)
{
	if (state < P1_INC_MIN)
	{
		display_show_config_time(&p1_time, &p2_time, state);
	}
	else if (state < MOVES1)
	{
		display_show_config_inc(&p1_inc, &p2_inc, state);
	}
	else if (state < BONUS_HOURS)
	{
		display_show_config_moves(moves, state);
	}
	else if (state < CONFIG_DONE)
	{
		display_show_config_bonus(&bonus, state);
	}
	else
	{

	}
}