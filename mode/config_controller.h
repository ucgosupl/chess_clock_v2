#ifndef CONFIG_CONTROLLER_H
#define CONFIG_CONTROLLER_H

#include "stm32f4xx.h"
#include <stdint.h>

typedef void (*config_completed_cb_t)(void);

typedef void (*on_entry_t)(config_completed_cb_t cb);
typedef void (*on_exit_t)(void);
typedef void (*on_plus_t)(void);
typedef void (*on_minus_t)(void);
typedef void (*on_left_t)(void);
typedef void (*on_right_t)(void);
typedef void (*display_t)(void);

struct config_controller
{
	on_entry_t on_entry;
	on_exit_t on_exit;
	on_plus_t on_plus;
	on_minus_t on_minus;
	on_left_t on_left;
	on_right_t on_right;
	display_t display;
};

__STATIC_FORCEINLINE uint8_t add_with_bounds(uint8_t val)
{
	return (val >= 9) ? 9 : ++val;
}

__STATIC_FORCEINLINE uint8_t sub_with_bounds(uint8_t val)
{
	return (val == 0) ? 0 : --val;
}

#endif /* CONFIG_CONTROLLER_H */