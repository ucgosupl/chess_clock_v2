#ifndef TURN_H_
#define TURN_H_

#include "player.h"

typedef void (*on_move_t)(enum player who_moved);

void turn_init(void);
void turn_subscribe(on_move_t cb);
void turn_update(void);
enum player turn_get(void);

#endif /* TURN_H_ */
