#include "unity/fixture/unity_fixture.h"
#include "fff/fff.h"

#include "assert.h"

#include "mode/mode.h"
#include "display_mocks.h"

static void go_to_config_state(const struct config_controller * config, enum config_state state);

TEST_GROUP(config_bonus);

TEST_SETUP(config_bonus)
{
    RESET_FAKE(display_show_config_time);
    RESET_FAKE(display_show_config_inc);
    RESET_FAKE(display_show_config_moves);
    RESET_FAKE(display_show_config_bonus);
    RESET_FAKE(config_completed);
    FFF_RESET_HISTORY();

    mode_set(BONUS_CUSTOM);

    const struct config_controller * config = mode_config_controller_get();
    config->on_entry(config_completed);
}

TEST_TEAR_DOWN(config_bonus)
{
    /* Cleanup after every test */
}

TEST(config_bonus, P1AddHours)
{
    const struct config_controller * config = mode_config_controller_get();

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus, P1SubtractHours)
{
    const struct config_controller * config = mode_config_controller_get();

    config->on_plus();
    config->on_minus();
    config->display();

    TEST_ASSERT_EQUAL(0, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus, P1SubtractHourBounds)
{
    const struct config_controller * config = mode_config_controller_get();

    config->on_minus();
    config->display();

    TEST_ASSERT_EQUAL(0, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus, P1AddHourBounds)
{
    const struct config_controller * config = mode_config_controller_get();

    for (int i = 0; i < 10; i++)
    {
        config->on_plus();
    }
    
    config->display();

    TEST_ASSERT_EQUAL(9, display_show_config_time_fake.arg0_val->h);
}

TEST(config_bonus, P1LeftBounds)
{
    const struct config_controller * config = mode_config_controller_get();

    config->on_left();
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->h);
}


TEST(config_bonus, P1AddTenMinutes)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_MIN1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->m1);
}

TEST(config_bonus, P1AddMinutes)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_MIN2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->m2);
}

TEST(config_bonus, P1AddTenSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_SEC1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->s1);
}

TEST(config_bonus, P1AddSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_SEC2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg0_val->s2);
}

TEST(config_bonus, P2AddHours)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_HOURS);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->h);
}

TEST(config_bonus, P2AddTenMinutes)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_MIN1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->m1);
}

TEST(config_bonus, P2AddMinutes)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_MIN2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->m2);
}

TEST(config_bonus, P2AddTenSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_SEC1);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->s1);
}

TEST(config_bonus, P2AddSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_SEC2);

    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_time_fake.arg1_val->s2);
}

TEST(config_bonus, P1IncrementAddMin)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_INC_MIN);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->m2);
}

TEST(config_bonus, P1IncrementAddTenSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_INC_SEC1);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->s1);
}

TEST(config_bonus, P1IncrementAddSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P1_INC_SEC2);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg0_val->s2);
}

TEST(config_bonus, P2IncrementAddMin)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_INC_MIN);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->m2);
}

TEST(config_bonus, P2IncrementAddTenSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_INC_SEC1);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->s1);
}

TEST(config_bonus, P2IncrementAddSeconds)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_INC_SEC2);
    
    config->on_plus();
    config->display();

    TEST_ASSERT_EQUAL(1, display_show_config_inc_fake.arg1_val->s2);
}

TEST(config_bonus, ConfigNotDone)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_INC_SEC2);

    TEST_ASSERT_EQUAL(0, config_completed_fake.call_count);
}

TEST(config_bonus, ConfigDone)
{
    const struct config_controller * config = mode_config_controller_get();

    go_to_config_state(config, P2_INC_SEC2 + 1);

    TEST_ASSERT_EQUAL(1, config_completed_fake.call_count);
}

static void go_to_config_state(const struct config_controller * config, enum config_state state)
{
    for (uint32_t i = 0; i < state; i++)
    {
        config->on_right();
    }
}
