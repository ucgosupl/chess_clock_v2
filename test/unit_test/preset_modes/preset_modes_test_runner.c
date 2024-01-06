#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(preset_modes)
{
   /* Test cases to run */
   RUN_TEST_CASE(preset_modes_fixed, TimeSet);
   RUN_TEST_CASE(preset_modes_fixed, Increment);
   RUN_TEST_CASE(preset_modes_fixed, BonusTime);
}
