#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(edit_fixed)
{
   /* Test cases to run */
   RUN_TEST_CASE(edit_fixed, P1AddHours);
   RUN_TEST_CASE(edit_fixed, P1SubtractHours);
   RUN_TEST_CASE(edit_fixed, P1SubtractHourBounds);
   RUN_TEST_CASE(edit_fixed, P1AddHourBounds);
   RUN_TEST_CASE(edit_fixed, P1LeftBounds);

   RUN_TEST_CASE(edit_fixed, P1AddTenMinutes);
   RUN_TEST_CASE(edit_fixed, P1AddMinutes);
   RUN_TEST_CASE(edit_fixed, P1AddTenSeconds);
   RUN_TEST_CASE(edit_fixed, P1AddSeconds);

   RUN_TEST_CASE(edit_fixed, P2AddHours);
   RUN_TEST_CASE(edit_fixed, P2AddTenMinutes);
   RUN_TEST_CASE(edit_fixed, P2AddMinutes);
   RUN_TEST_CASE(edit_fixed, P2AddTenSeconds);
   RUN_TEST_CASE(edit_fixed, P2AddSeconds);

   RUN_TEST_CASE(edit_fixed, EditNotDone);
   RUN_TEST_CASE(edit_fixed, EditDone);
}

TEST_GROUP_RUNNER(edit_bonus)
{
   /* Test cases to run */
   RUN_TEST_CASE(edit_bonus, P1AddHours);
   RUN_TEST_CASE(edit_bonus, P1SubtractHours);
   RUN_TEST_CASE(edit_bonus, P1SubtractHourBounds);
   RUN_TEST_CASE(edit_bonus, P1AddHourBounds);
   RUN_TEST_CASE(edit_bonus, P1LeftBounds);

   RUN_TEST_CASE(edit_bonus, P1AddTenMinutes);
   RUN_TEST_CASE(edit_bonus, P1AddMinutes);
   RUN_TEST_CASE(edit_bonus, P1AddTenSeconds);
   RUN_TEST_CASE(edit_bonus, P1AddSeconds);

   RUN_TEST_CASE(edit_bonus, P2AddHours);
   RUN_TEST_CASE(edit_bonus, P2AddTenMinutes);
   RUN_TEST_CASE(edit_bonus, P2AddMinutes);
   RUN_TEST_CASE(edit_bonus, P2AddTenSeconds);
   RUN_TEST_CASE(edit_bonus, P2AddSeconds);

   RUN_TEST_CASE(edit_bonus, EditNotDone);
   RUN_TEST_CASE(edit_bonus, EditDone);
}

TEST_GROUP_RUNNER(edit_bonus_control)
{
   /* Test cases to run */
   RUN_TEST_CASE(edit_bonus_control, P1AddHours);
   RUN_TEST_CASE(edit_bonus_control, P1SubtractHours);
   RUN_TEST_CASE(edit_bonus_control, P1SubtractHourBounds);
   RUN_TEST_CASE(edit_bonus_control, P1AddHourBounds);
   RUN_TEST_CASE(edit_bonus_control, P1LeftBounds);

   RUN_TEST_CASE(edit_bonus_control, P1AddTenMinutes);
   RUN_TEST_CASE(edit_bonus_control, P1AddMinutes);
   RUN_TEST_CASE(edit_bonus_control, P1AddTenSeconds);
   RUN_TEST_CASE(edit_bonus_control, P1AddSeconds);

   RUN_TEST_CASE(edit_bonus_control, P2AddHours);
   RUN_TEST_CASE(edit_bonus_control, P2AddTenMinutes);
   RUN_TEST_CASE(edit_bonus_control, P2AddMinutes);
   RUN_TEST_CASE(edit_bonus_control, P2AddTenSeconds);
   RUN_TEST_CASE(edit_bonus_control, P2AddSeconds);

   RUN_TEST_CASE(edit_bonus_control, P1AddTenMoves);
   RUN_TEST_CASE(edit_bonus_control, P1AddMoves);
   RUN_TEST_CASE(edit_bonus_control, P2AddTenMoves);
   RUN_TEST_CASE(edit_bonus_control, P2AddMoves);

   RUN_TEST_CASE(edit_bonus_control, EditNotDone);
   RUN_TEST_CASE(edit_bonus_control, EditDone);
}

TEST_GROUP_RUNNER(edit_fixed_control)
{
   /* Test cases to run */
   RUN_TEST_CASE(edit_fixed_control, P1AddHours);
   RUN_TEST_CASE(edit_fixed_control, P1SubtractHours);
   RUN_TEST_CASE(edit_fixed_control, P1SubtractHourBounds);
   RUN_TEST_CASE(edit_fixed_control, P1AddHourBounds);
   RUN_TEST_CASE(edit_fixed_control, P1LeftBounds);

   RUN_TEST_CASE(edit_fixed_control, P1AddTenMinutes);
   RUN_TEST_CASE(edit_fixed_control, P1AddMinutes);
   RUN_TEST_CASE(edit_fixed_control, P1AddTenSeconds);
   RUN_TEST_CASE(edit_fixed_control, P1AddSeconds);

   RUN_TEST_CASE(edit_fixed_control, P2AddHours);
   RUN_TEST_CASE(edit_fixed_control, P2AddTenMinutes);
   RUN_TEST_CASE(edit_fixed_control, P2AddMinutes);
   RUN_TEST_CASE(edit_fixed_control, P2AddTenSeconds);
   RUN_TEST_CASE(edit_fixed_control, P2AddSeconds);

   RUN_TEST_CASE(edit_fixed_control, P1AddTenMoves);
   RUN_TEST_CASE(edit_fixed_control, P1AddMoves);
   RUN_TEST_CASE(edit_fixed_control, P2AddTenMoves);
   RUN_TEST_CASE(edit_fixed_control, P2AddMoves);

   RUN_TEST_CASE(edit_fixed_control, EditNotDone);
   RUN_TEST_CASE(edit_fixed_control, EditDone);
}
