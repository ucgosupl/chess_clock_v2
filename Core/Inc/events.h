#ifndef EVENTS_H_
#define EVENTS_H_

#include <stdint.h>

#define EVENT_BUTTON_PLUS			(1 << 0)
#define EVENT_BUTTON_MINUS			(1 << 1)
#define EVENT_BUTTON_LEFT			(1 << 2)
#define EVENT_BUTTON_RIGHT			(1 << 3)
#define EVENT_BUTTON_PLAY			(1 << 4)

#define EVENT_IS_ACTIVE(events, e)	(0 != (events & (e)))
#define EVENT_SET(events, e)		(events |= (e))

typedef uint32_t events_t;

#endif /* EVENTS_H_ */
