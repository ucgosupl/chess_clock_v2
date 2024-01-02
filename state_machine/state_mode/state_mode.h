#ifndef STATE_MODE_STATE_MODE_H_
#define STATE_MODE_STATE_MODE_H_

#include "events/events.h"
#include "../state.h"

void mode_on_entry(void);
enum state mode_on_tick(events_t events);
void mode_on_exit(void);

#endif /* STATE_MODE_STATE_MODE_H_ */
