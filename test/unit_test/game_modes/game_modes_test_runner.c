#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(game_mode_fixed)
{
   RUN_TEST_CASE(game_mode_fixed, TimeSetAfterConfig);
   RUN_TEST_CASE(game_mode_fixed, P1TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_fixed, P2TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_fixed, P1TimeNotChangedAfterMove);
   RUN_TEST_CASE(game_mode_fixed, P2TimeNotChangedAfterMove);
}

TEST_GROUP_RUNNER(game_mode_bonus)
{
   RUN_TEST_CASE(game_mode_bonus, TimeSetAfterConfig);
   RUN_TEST_CASE(game_mode_bonus, P1TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_bonus, P2TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_bonus, IncrementAddedAfterP1AfterMove);
   RUN_TEST_CASE(game_mode_bonus, IncrementAddedAfterP2AfterMove);
}

TEST_GROUP_RUNNER(game_mode_fixed_control)
{
   RUN_TEST_CASE(game_mode_fixed_control, TimeSetAfterConfig);
   RUN_TEST_CASE(game_mode_fixed_control, P1TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_fixed_control, P2TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_fixed_control, P1TimeNotChangedAfterMove);
   RUN_TEST_CASE(game_mode_fixed_control, P2TimeNotChangedAfterMove);
   RUN_TEST_CASE(game_mode_fixed_control, NoBonusOneMoveBeforeControl);
   RUN_TEST_CASE(game_mode_fixed_control, P1BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_fixed_control, P2BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_fixed_control, P1BonusAddedThenP2BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_fixed_control, P2BonusAddedThenP1BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_fixed_control, NoSecondBonusAfterNextMove);
}

TEST_GROUP_RUNNER(game_mode_bonus_control)
{
   RUN_TEST_CASE(game_mode_bonus_control, TimeSetAfterConfig);
   RUN_TEST_CASE(game_mode_bonus_control, P1TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_bonus_control, P2TimeDecreasedAfterUpdate);
   RUN_TEST_CASE(game_mode_bonus_control, IncrementAddedAfterP1AfterMove);
   RUN_TEST_CASE(game_mode_bonus_control, IncrementAddedAfterP2AfterMove);
   RUN_TEST_CASE(game_mode_bonus_control, NoBonusOneMoveBeforeControl);
   RUN_TEST_CASE(game_mode_bonus_control, P1BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_bonus_control, P2BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_bonus_control, P1BonusAddedThenP2BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_bonus_control, P2BonusAddedThenP1BonusAddedAfterControl);
   RUN_TEST_CASE(game_mode_bonus_control, NoSecondBonusAfterNextMove);
}
