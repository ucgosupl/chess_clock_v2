#include "unity/fixture/unity_fixture.h"

static void run_all_tests(void);

int main(int argc, const char **argv)
{
   return UnityMain(argc, argv, run_all_tests);
}

static void run_all_tests(void)
{
   RUN_TEST_GROUP(game_mode_fixed);
   RUN_TEST_GROUP(game_mode_bonus);
   RUN_TEST_GROUP(game_mode_fixed_control);
   RUN_TEST_GROUP(game_mode_bonus_control);
}