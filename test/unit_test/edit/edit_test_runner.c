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
