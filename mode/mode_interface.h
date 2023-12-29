#ifndef MODE_INTERFACE_H_
#define MODE_INTERFACE_H_

#include "time.h"

#include "turn/turn.h"

typedef uint32_t moves_t;

typedef void (*on_start)(void);
typedef void (*on_time_update)(enum turn player);
typedef void (*on_move)(enum turn player);
typedef ms_t (*time_get)(enum turn player);

struct mode_interface
{
	on_start on_start;
	on_time_update on_time_update;
	on_move on_move;
	time_get time_get;
};

#endif /* MODE_INTERFACE_H_ */
