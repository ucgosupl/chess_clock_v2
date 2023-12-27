#ifndef MODE_INTERFACE_H_
#define MODE_INTERFACE_H_

#include "time.h"

enum state {NOT_STARTED, P1, P2};

typedef void (*on_start)(void);
typedef void (*on_time_update)(enum state game_state);
typedef void (*on_move)(enum state player);
typedef ms_t (*time_get)(enum state player);

struct mode_interface
{
	on_start on_start;
	on_time_update on_time_update;
	on_move on_move;
	time_get time_get;
};

#endif /* MODE_INTERFACE_H_ */
