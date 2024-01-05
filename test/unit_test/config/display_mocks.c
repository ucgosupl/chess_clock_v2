#include "display_mocks.h"

DEFINE_FFF_GLOBALS;

DEFINE_FAKE_VOID_FUNC3(display_show_config_time, struct config_time *, struct config_time *, uint32_t);
DEFINE_FAKE_VOID_FUNC3(display_show_config_inc, struct config_time *, struct config_time *, uint32_t);
DEFINE_FAKE_VOID_FUNC2(display_show_config_moves, uint32_t, uint32_t);
DEFINE_FAKE_VOID_FUNC2(display_show_config_bonus, struct config_time *, uint32_t);

DEFINE_FAKE_VOID_FUNC0(config_completed);