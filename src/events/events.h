#ifndef EVENTS_H_
#define EVENTS_H_

#include <stdint.h>

#define EVENT_ID_PLUS               0
#define EVENT_ID_MINUS              1
#define EVENT_ID_LEFT               2
#define EVENT_ID_RIGHT              3
#define EVENT_ID_PLAY               4
#define EVENT_ID_EDIT               5
#define EVENT_ID_MAX                EVENT_ID_EDIT

#define EVENT_BUTTON_PLUS			(1 << EVENT_ID_PLUS)
#define EVENT_BUTTON_MINUS			(1 << EVENT_ID_MINUS)
#define EVENT_BUTTON_LEFT			(1 << EVENT_ID_LEFT)
#define EVENT_BUTTON_RIGHT			(1 << EVENT_ID_RIGHT)
#define EVENT_BUTTON_PLAY			(1 << EVENT_ID_PLAY)
#define EVENT_BUTTON_EDIT			(1 << EVENT_ID_EDIT)

#define EVENT_IS_ACTIVE(events, e)	(0 != (events & (e)))
#define EVENT_SET(events, e)		(events |= (e))

typedef uint32_t events_t;

void events_init(void);
events_t events_update(void);

#endif /* EVENTS_H_ */
