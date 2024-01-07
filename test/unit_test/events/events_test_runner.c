#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(events)
{
   RUN_TEST_CASE(events, NoEvents);

   RUN_TEST_CASE(events, EventPlus);
   RUN_TEST_CASE(events, EventPlusCooldown);

   RUN_TEST_CASE(events, EventMinus);
   RUN_TEST_CASE(events, EventMinusCooldown);
   
   RUN_TEST_CASE(events, EventLeft);
   RUN_TEST_CASE(events, EventLeftCooldown);

   RUN_TEST_CASE(events, EventRight);
   RUN_TEST_CASE(events, EventRightCooldown);

   RUN_TEST_CASE(events, NoEventPlayIfStillPressed);
   RUN_TEST_CASE(events, EventPlayAfterReleased);
   RUN_TEST_CASE(events, SecondEventPlay);
   RUN_TEST_CASE(events, EventEditAfterLongPress);
}
