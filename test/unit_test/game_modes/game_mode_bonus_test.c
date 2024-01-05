#include "unity/fixture/unity_fixture.h"

#include "assert.h"

#include "mode/mode.h"

static const ms_t START_TIME = TIME_TO_MS(0, 5, 0);
static const ms_t INCREMENT = TIME_TO_MS(0, 0, 5);

TEST_GROUP(game_mode_bonus);

TEST_SETUP(game_mode_bonus)
{
    mode_set(BONUS_CUSTOM);
    const struct mode_builder *builder = mode_builder_get();
    builder->init();
    builder->set_time(PLAYER_BOTH, START_TIME);
    builder->set_increment(PLAYER_BOTH, INCREMENT);
}

TEST_TEAR_DOWN(game_mode_bonus)
{

}

TEST(game_mode_bonus, TimeSetAfterConfig)
{
    const struct game_controller *mode = mode_game_controller_get();

    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER2));
}

TEST(game_mode_bonus, P1TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT - 1, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER2));
}

TEST(game_mode_bonus, P2TimeDecreasedAfterUpdate)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT - 1, mode->time_get(PLAYER2));
}

TEST(game_mode_bonus, IncrementAddedAfterP1AfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER1);
    mode->on_move(PLAYER1);

    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1 + 2 * INCREMENT, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER2));
}

TEST(game_mode_bonus, IncrementAddedAfterP2AfterMove)
{
    const struct game_controller *mode = mode_game_controller_get();

    mode->on_time_update(PLAYER2);
    mode->on_move(PLAYER2);

    TEST_ASSERT_EQUAL_UINT32(START_TIME + INCREMENT, mode->time_get(PLAYER1));
    TEST_ASSERT_EQUAL_UINT32(START_TIME - 1 + 2 * INCREMENT, mode->time_get(PLAYER2));
}
