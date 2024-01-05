#include "unity/fixture/unity_fixture.h"

#include "assert.h"

#include "mode/mode.h"

static const ms_t START_TIME = TIME_TO_MS(0, 5, 0);

TEST_GROUP(game_mode_fixed);

TEST_SETUP(game_mode_fixed)
{
    mode_set(FIXED_CUSTOM);
    const struct mode_builder *builder = mode_builder_get();
    builder->init();
    builder->set_time(PLAYER_BOTH, START_TIME);
}

TEST_TEAR_DOWN(game_mode_fixed)
{

}

TEST(game_mode_fixed, TimeSetAfterConfig)
{
    const struct game_controller *mode = mode_game_controller_get();

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed, P1TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed, P2TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed, P1TimeNotChangedAfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);
    mode->on_move(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER2));
}

TEST(game_mode_fixed, P2TimeNotChangedAfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);
    mode->on_move(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1, mode->time_get(PLAYER2));
}
