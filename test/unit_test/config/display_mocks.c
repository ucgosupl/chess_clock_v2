#include "display_mocks.h"

DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VOID_FUNC3(display_show_config_time, struct config_time *, struct config_time *, enum config_state);
DEFINE_FAKE_VOID_FUNC3(display_show_config_inc, struct config_time *, struct config_time *, enum config_state);
DEFINE_FAKE_VOID_FUNC2(display_show_config_moves, struct config_moves *, enum config_state);
DEFINE_FAKE_VOID_FUNC2(display_show_config_bonus, struct config_time *, enum config_state);

DEFINE_FAKE_VOID_FUNC3(display_show_edit_time, struct config_time *, struct config_time *, enum edit_state);
DEFINE_FAKE_VOID_FUNC3(display_show_edit_moves, struct config_moves *, struct config_moves *, enum edit_state);

DEFINE_FAKE_VOID_FUNC0(config_completed);