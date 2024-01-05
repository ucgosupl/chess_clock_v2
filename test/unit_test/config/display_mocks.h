#ifndef DISPLAY_MOCKS_H
#define DISPLAY_MOCKS_H

#include "display/display.h"

#include "fff/fff.h"

DECLARE_FAKE_VOID_FUNC3(display_show_config_time, struct config_time *, struct config_time *, uint32_t);
DECLARE_FAKE_VOID_FUNC3(display_show_config_inc, struct config_time *, struct config_time *, uint32_t);
DECLARE_FAKE_VOID_FUNC2(display_show_config_moves, uint32_t, uint32_t);
DECLARE_FAKE_VOID_FUNC2(display_show_config_bonus, struct config_time *, uint32_t);

DECLARE_FAKE_VOID_FUNC0(config_completed);

#endif /* DISPLAY_MOCKS_H */