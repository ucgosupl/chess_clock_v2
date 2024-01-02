#ifndef STATE_GAME_H_
#define STATE_GAME_H_

#include <stdint.h>

#include "events/events.h"
#include "../state.h"

void game_on_entry(void);
enum state game_on_tick(events_t events);
void game_on_exit(void);
void game_time_update(void);

#endif /* STATE_GAME_H_ */
