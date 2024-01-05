#include "unity/fixture/unity_fixture.h"
#include "fff/fff.h"

#include "assert.h"

#include "config/config.h"
#include "mode/mode.h"

#include "display_mocks.h"

static void go_to_config_state(const struct config_interface * config, enum config_state state);

TEST_GROUP(config_bonus_control);

TEST_SETUP(config_bonus_control)
{
    RESET_FAKE(display_show_config_time);
    RESET_FAKE(display_show_config_inc);
    RESET_FAKE(display_show_config_moves);
    RESET_FAKE(display_show_config_bonus);
    RESET_FAKE(config_completed);
    FFF_RESET_HISTORY();

    mode_set(BONUSC_CUSTOM);

    const struct config_interface * config = mode_config_get();
    config->on_entry(config_completed);
}

TEST_TEAR_DOWN(config_bonus_control)
{
    /* Cleanup after every test */
}

TEST(config_bonus_control, P1AddHours)
{
    const struct config_interface * config = mode_config_get();

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus_control, P1SubtractHours)
{
    const struct config_interface * config = mode_config_get();

    config->on_plus();
    config->on_minus();
    config->display();

    TEST_ASSERT_EQUAL(0, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus_control, P1SubtractHourBounds)
{
    const struct config_interface * config = mode_config_get();

    config->on_minus();
    config->display();

    TEST_ASSERT_EQUAL(0, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus_control, P1AddHourBounds)
{
    const struct config_interface * config = mode_config_get();

    for (int i = 0; i < 10; i++)
    {
        config->on_plus();
    }
    
    config->display();

    TEST_ASSERT_EQUAL(9, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus_control, P1LeftBounds)
{
    const struct config_interface * config = mode_config_get();

    config->on_left();
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->h);
}


TEST(config_bonus_control, P1AddTenMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_MIN1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->m1);
}

TEST(config_bonus_control, P1AddMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_MIN2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->m2);
}

TEST(config_bonus_control, P1AddTenSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_SEC1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->s1);
}

TEST(config_bonus_control, P1AddSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_SEC2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->s2);
}

TEST(config_bonus_control, P2AddHours)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_HOURS);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->h);
}

TEST(config_bonus_control, P2AddTenMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_MIN1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->m1);
}

TEST(config_bonus_control, P2AddMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_MIN2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->m2);
}

TEST(config_bonus_control, P2AddTenSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_SEC1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->s1);
}

TEST(config_bonus_control, P2AddSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_SEC2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->s2);
}

TEST(config_bonus_control, P1IncrementAddMin)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_INC_MIN);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->m2);
}

TEST(config_bonus_control, P1IncrementAddTenSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_INC_SEC1);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->s1);
}

TEST(config_bonus_control, P1IncrementAddSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P1_INC_SEC2);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->s2);
}

TEST(config_bonus_control, P2IncrementAddMin)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_INC_MIN);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->m2);
}

TEST(config_bonus_control, P2IncrementAddTenSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_INC_SEC1);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->s1);
}

TEST(config_bonus_control, P2IncrementAddSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, P2_INC_SEC2);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->s2);
}

TEST(config_bonus_control, AddTenMoves)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, MOVES1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_moves_fake.arg0_val->moves1);
}

TEST(config_bonus_control, AddMoves)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, MOVES2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_moves_fake.arg0_val->moves2);
}

TEST(config_bonus_control, BonusAddHours)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_HOURS);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_bonus_fake.arg0_val->h);
}

TEST(config_bonus_control, BonusAddTenMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_MIN1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_bonus_fake.arg0_val->m1);
}

TEST(config_bonus_control, BonusAddMinutes)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_MIN2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_bonus_fake.arg0_val->m2);
}

TEST(config_bonus_control, BonusAddTenSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_SEC1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_bonus_fake.arg0_val->s1);
}

TEST(config_bonus_control, BonusAddSeconds)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_SEC2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_bonus_fake.arg0_val->s2);
}

TEST(config_bonus_control, ConfigNotDone)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_SEC2);

    TEST_ASSERT_EQUAL(0, config_completed_fake.call_count);
}

TEST(config_bonus_control, ConfigDone)
{
    const struct config_interface * config = mode_config_get();

    go_to_config_state(config, BONUS_SEC2 + 1);

    TEST_ASSERT_EQUAL(1, config_completed_fake.call_count);
}

static void go_to_config_state(const struct config_interface * config, enum config_state state)
{
    for (uint32_t i = 0; i < state; i++)
    {
        config->on_right();
    }
}
