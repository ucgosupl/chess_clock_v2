#include "turn.h"

#include <stdlib.h>

#include "buttons/buttons.h"
#include "periodic_tasks/periodic_tasks.h"

static enum player turn;

static on_move_t move_cb = NULL;

void turn_init(void)
{
	turn = PLAYER1;
	buttons_init();
	periodic_subscribe_100ms(turn_update);
}

void turn_subscribe(on_move_t cb)
{
	move_cb = cb;
}

void turn_update(void)
{
	if (buttons_is_p1_pressed())
	{
		if ((turn == PLAYER2) && (move_cb != NULL))
		{
			move_cb(PLAYER2);
		}
		turn = PLAYER1;
	}
	if (buttons_is_p2_pressed())
	{
		if ((turn == PLAYER1) && (move_cb != NULL))
		{
			move_cb(PLAYER1);
		}
		turn = PLAYER2;
	}
}

enum player turn_get(void)
{
	return turn;
}
