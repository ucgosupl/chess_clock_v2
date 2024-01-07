#ifndef DISPLAY_MOCKS_H
#define DISPLAY_MOCKS_H

#include "display/display.h"

#include "fff/fff.h"

DECLARE_FAKE_VOID_FUNC3(display_show_config_time, struct config_time *, struct config_time *, enum config_state);
DECLARE_FAKE_VOID_FUNC3(display_show_config_inc, struct config_time *, struct config_time *, enum config_state);
DECLARE_FAKE_VOID_FUNC2(display_show_config_moves, struct config_moves *, enum config_state);
DECLARE_FAKE_VOID_FUNC2(display_show_config_bonus, struct config_time *, enum config_state);

DECLARE_FAKE_VOID_FUNC3(display_show_edit_time, struct config_time *, struct config_time *, enum edit_state);
DECLARE_FAKE_VOID_FUNC3(display_show_edit_moves, struct config_moves *, struct config_moves *, enum edit_state);

DECLARE_FAKE_VOID_FUNC0(config_completed);

#endif /* DISPLAY_MOCKS_H */