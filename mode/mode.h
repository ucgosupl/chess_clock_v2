#ifndef MODE_H_
#define MODE_H_

#include <stdint.h>
#include "events/events.h"

enum mode
{
	FIXED_CUSTOM,
	BONUS_CUSTOM,
	BONUSC_CUSTOM,

	FIXED_1M,
	FIXED_5M,
	FIXED_15M,
	FIXED_30M,
	FIXED_1H,
	FIXED_1H_30M,

	BONUS_1M_1S,
	BONUS_3M_2S,
	BOUNS_5M_3S,
	BONUS_10M_5S,
	BONUS_15M_10S,
	BONUS_1H30M_30S,

	BONUSC_1H30M_30S_40MOV_30M,
	BONUSC_1H30M_0S_30MOV_1H,

	MODES_MAX,
};

void mode_on_entry(void);
uint32_t mode_on_tick(events_t events);
void mode_on_exit(void);
enum mode mode_get(void);

#endif /* MODE_H_ */