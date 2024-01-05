#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(config_fixed)
{
   /* Test cases to run */
   RUN_TEST_CASE(config_fixed, P1AddHours);
   RUN_TEST_CASE(config_fixed, P1SubtractHours);
   RUN_TEST_CASE(config_fixed, P1SubtractHourBounds);
   RUN_TEST_CASE(config_fixed, P1AddHourBounds);
   RUN_TEST_CASE(config_fixed, P1LeftBounds);
   RUN_TEST_CASE(config_fixed, P1AddTenMinutes);
   RUN_TEST_CASE(config_fixed, P1AddMinutes);
   RUN_TEST_CASE(config_fixed, P1AddTenSeconds);
   RUN_TEST_CASE(config_fixed, P1AddSeconds);

   RUN_TEST_CASE(config_fixed, P2AddHours);
   RUN_TEST_CASE(config_fixed, P2AddTenMinutes);
   RUN_TEST_CASE(config_fixed, P2AddMinutes);
   RUN_TEST_CASE(config_fixed, P2AddTenSeconds);
   RUN_TEST_CASE(config_fixed, P2AddSeconds);

   RUN_TEST_CASE(config_fixed, ConfigNotDone);
   RUN_TEST_CASE(config_fixed, ConfigDone);
}

TEST_GROUP_RUNNER(config_bonus)
{
   /* Test cases to run */
   RUN_TEST_CASE(config_bonus, P1AddHours);
   RUN_TEST_CASE(config_bonus, P1SubtractHours);
   RUN_TEST_CASE(config_bonus, P1SubtractHourBounds);
   RUN_TEST_CASE(config_bonus, P1AddHourBounds);
   RUN_TEST_CASE(config_bonus, P1LeftBounds);
   RUN_TEST_CASE(config_bonus, P1AddTenMinutes);
   RUN_TEST_CASE(config_bonus, P1AddMinutes);
   RUN_TEST_CASE(config_bonus, P1AddTenSeconds);
   RUN_TEST_CASE(config_bonus, P1AddSeconds);

   RUN_TEST_CASE(config_bonus, P2AddHours);
   RUN_TEST_CASE(config_bonus, P2AddTenMinutes);
   RUN_TEST_CASE(config_bonus, P2AddMinutes);
   RUN_TEST_CASE(config_bonus, P2AddTenSeconds);
   RUN_TEST_CASE(config_bonus, P2AddSeconds);

   RUN_TEST_CASE(config_bonus, P1IncrementAddMin);
   RUN_TEST_CASE(config_bonus, P1IncrementAddTenSeconds);
   RUN_TEST_CASE(config_bonus, P1IncrementAddSeconds);

   RUN_TEST_CASE(config_bonus, P2IncrementAddMin);
   RUN_TEST_CASE(config_bonus, P2IncrementAddTenSeconds);
   RUN_TEST_CASE(config_bonus, P2IncrementAddSeconds);

   RUN_TEST_CASE(config_bonus, ConfigNotDone);
   RUN_TEST_CASE(config_bonus, ConfigDone);
}

TEST_GROUP_RUNNER(config_bonus_control)
{
   /* Test cases to run */
   RUN_TEST_CASE(config_bonus_control, P1AddHours);
   RUN_TEST_CASE(config_bonus_control, P1SubtractHours);
   RUN_TEST_CASE(config_bonus_control, P1SubtractHourBounds);
   RUN_TEST_CASE(config_bonus_control, P1AddHourBounds);
   RUN_TEST_CASE(config_bonus_control, P1LeftBounds);
   RUN_TEST_CASE(config_bonus_control, P1AddTenMinutes);
   RUN_TEST_CASE(config_bonus_control, P1AddMinutes);
   RUN_TEST_CASE(config_bonus_control, P1AddTenSeconds);
   RUN_TEST_CASE(config_bonus_control, P1AddSeconds);

   RUN_TEST_CASE(config_bonus_control, P2AddHours);
   RUN_TEST_CASE(config_bonus_control, P2AddTenMinutes);
   RUN_TEST_CASE(config_bonus_control, P2AddMinutes);
   RUN_TEST_CASE(config_bonus_control, P2AddTenSeconds);
   RUN_TEST_CASE(config_bonus_control, P2AddSeconds);

   RUN_TEST_CASE(config_bonus_control, P1IncrementAddMin);
   RUN_TEST_CASE(config_bonus_control, P1IncrementAddTenSeconds);
   RUN_TEST_CASE(config_bonus_control, P1IncrementAddSeconds);
   
   RUN_TEST_CASE(config_bonus_control, P2IncrementAddMin);
   RUN_TEST_CASE(config_bonus_control, P2IncrementAddTenSeconds);
   RUN_TEST_CASE(config_bonus_control, P2IncrementAddSeconds);

   RUN_TEST_CASE(config_bonus_control, AddTenMoves);
   RUN_TEST_CASE(config_bonus_control, AddMoves);

   RUN_TEST_CASE(config_bonus_control, BonusAddHours);
   RUN_TEST_CASE(config_bonus_control, BonusAddTenMinutes);
   RUN_TEST_CASE(config_bonus_control, BonusAddMinutes);
   RUN_TEST_CASE(config_bonus_control, BonusAddTenSeconds);
   RUN_TEST_CASE(config_bonus_control, BonusAddSeconds);

   RUN_TEST_CASE(config_bonus_control, ConfigNotDone);
   RUN_TEST_CASE(config_bonus_control, ConfigDone);
}

TEST_GROUP_RUNNER(config_fixed_control)
{
   /* Test cases to run */
   RUN_TEST_CASE(config_fixed_control, P1AddHours);
   RUN_TEST_CASE(config_fixed_control, P1SubtractHours);
   RUN_TEST_CASE(config_fixed_control, P1SubtractHourBounds);
   RUN_TEST_CASE(config_fixed_control, P1AddHourBounds);
   RUN_TEST_CASE(config_fixed_control, P1LeftBounds);
   RUN_TEST_CASE(config_fixed_control, P1AddTenMinutes);
   RUN_TEST_CASE(config_fixed_control, P1AddMinutes);
   RUN_TEST_CASE(config_fixed_control, P1AddTenSeconds);
   RUN_TEST_CASE(config_fixed_control, P1AddSeconds);

   RUN_TEST_CASE(config_fixed_control, P2AddHours);
   RUN_TEST_CASE(config_fixed_control, P2AddTenMinutes);
   RUN_TEST_CASE(config_fixed_control, P2AddMinutes);
   RUN_TEST_CASE(config_fixed_control, P2AddTenSeconds);
   RUN_TEST_CASE(config_fixed_control, P2AddSeconds);

   RUN_TEST_CASE(config_fixed_control, AddTenMoves);
   RUN_TEST_CASE(config_fixed_control, AddMoves);

   RUN_TEST_CASE(config_fixed_control, BonusAddHours);
   RUN_TEST_CASE(config_fixed_control, BonusAddTenMinutes);
   RUN_TEST_CASE(config_fixed_control, BonusAddMinutes);
   RUN_TEST_CASE(config_fixed_control, BonusAddTenSeconds);
   RUN_TEST_CASE(config_fixed_control, BonusAddSeconds);

   RUN_TEST_CASE(config_fixed_control, ConfigNotDone);
   RUN_TEST_CASE(config_fixed_control, ConfigDone);

   RUN_TEST_CASE(config_fixed_control, OnLeftSkipIncrement);
}