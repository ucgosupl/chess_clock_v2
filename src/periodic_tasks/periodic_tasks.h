#ifndef PERIODIC_TASKS_H_
#define PERIODIC_TASKS_H_

#include <stdint.h>

typedef void (*periodic_cb_t)(void);

void periodic_init(void);

void periodic_subscribe_1ms(periodic_cb_t cb);
void periodic_subscribe_100ms(periodic_cb_t cb);

void periodic_tick_1ms(void);

#endif /* PERIODIC_TASKS_H_ */
