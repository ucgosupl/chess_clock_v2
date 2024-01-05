#include "unity/fixture/unity_fixture.h"

#include "assert.h"

#include "mode/mode.h"

static const ms_t START_TIME = TIME_TO_MS(0, 5, 0);
static const moves_t MOVES = 5;
static const ms_t BONUS_TIME = TIME_TO_MS(0, 5, 0);

TEST_GROUP(game_mode_fixed_control);

TEST_SETUP(game_mode_fixed_control)
{
    mode_set(FIXEDC_CUSTOM);
    const struct mode_builder *builder = mode_builder_get();
    builder->init();
    builder->set_time(PLAYER_BOTH, START_TIME);
    builder->set_moves(PLAYER_BOTH, MOVES);
    builder->set_bonus(PLAYER_BOTH, BONUS_TIME);
}

TEST_TEAR_DOWN(game_mode_fixed_control)
{

}

TEST(game_mode_fixed_control, TimeSetAfterConfig)
{
    const struct game_controller *mode = mode_game_controller_get();

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P1TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P2TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P1TimeNotChangedAfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);
    mode->on_move(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P2TimeNotChangedAfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);
    mode->on_move(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, NoBonusOneMoveBeforeControl)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES - 1; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P1BonusAddedAfterControl)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES - 1; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    mode->on_move(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P2BonusAddedAfterControl)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES - 1; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    mode->on_move(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P1BonusAddedThenP2BonusAddedAfterControl)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES - 1; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    mode->on_move(PLAYER1);
    mode->on_move(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, P2BonusAddedThenP1BonusAddedAfterControl)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES - 1; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    mode->on_move(PLAYER2);
    mode->on_move(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed_control, NoSecondBonusAfterNextMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    for (moves_t i = 0; i < MOVES; i++)
    {
        mode->on_move(PLAYER1);
        mode->on_move(PLAYER2);
    }

    mode->on_move(PLAYER1);
    mode->on_move(PLAYER2);
    
    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + BONUS_TIME, mode->time_get(PLAYER2));
}
