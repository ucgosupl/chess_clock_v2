#ifndef MODE_INTERFACE_H_
#define MODE_INTERFACE_H_

#include "time.h"
#include "player.h"

typedef void (*on_start)(void);
typedef void (*on_time_update)(enum player player);
typedef void (*on_move)(enum player player);
typedef ms_t (*time_get)(enum player player);

struct mode_interface
{
	on_start on_start;
	on_time_update on_time_update;
	on_move on_move;
	time_get time_get;
};

#endif /* MODE_INTERFACE_H_ */
