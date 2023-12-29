#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "events/events.h"

void state_machine_init(void);
void state_machine_tick(events_t events);

#endif /* STATE_MACHINE_H_ */
