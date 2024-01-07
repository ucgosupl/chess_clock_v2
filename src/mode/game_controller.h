#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

#include "time.h"
#include "player.h"
#include "moves.h"

typedef void (*on_start_t)(void);
typedef void (*on_time_update_t)(enum player player);
typedef void (*on_move_t)(enum player player);
typedef ms_t (*time_get_t)(enum player player);
typedef moves_t (*moves_get_t)(enum player player);

struct game_controller
{
	on_start_t on_start;
	on_time_update_t on_time_update;
	on_move_t on_move;
	time_get_t time_get;
	moves_get_t moves_get;
};

#endif /* GAME_CONTROLLER_H_ */
