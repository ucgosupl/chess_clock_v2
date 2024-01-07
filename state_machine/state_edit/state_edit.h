#ifndef STATE_EDIT_H_
#define STATE_EDIT_H_

#include "events/events.h"
#include "../state.h"

void edit_on_entry(void);
enum state edit_on_tick(events_t events);
void edit_on_exit(void);

#endif /* STATE_EDIT_H_ */
