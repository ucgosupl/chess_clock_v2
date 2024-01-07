#include "unity/fixture/unity_fixture.h"

#include "assert.h"

#include "mode/mode.h"
#include "display_mocks.h"

static void go_to_edit_state(const struct config_controller * edit, enum edit_state state);

TEST_GROUP(edit_bonus);

TEST_SETUP(edit_bonus)
{
    RESET_FAKE(display_show_edit_time);
    RESET_FAKE(display_show_edit_moves);
    RESET_FAKE(config_completed);
    FFF_RESET_HISTORY();

    mode_set(BONUS_CUSTOM);

    const struct mode_builder * mode_builder = mode_builder_get();
    mode_builder->init();
    mode_builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 0, 0));
    mode_builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 0));

    const struct config_controller * edit = mode_edit_controller_get();
    edit->on_entry(config_completed);
}

TEST_TEAR_DOWN(edit_bonus)
{
    /* Cleanup after every test */
}

TEST(edit_bonus, P1AddHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus, P1SubtractHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_plus();
    edit->on_minus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus, P1SubtractHourBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_minus();
    edit->on_minus();
    edit->display();

    TEST_ASSERT_EQUAL(0, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus, P1AddHourBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    for (int i = 0; i < 10 - 1; i++)
    {
        edit->on_plus();
    }
    
    edit->display();

    TEST_ASSERT_EQUAL(9, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus, P1LeftBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_left();
    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus, P1AddTenMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MIN1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->m1);
}

TEST(edit_bonus, P1AddMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MIN2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->m2);
}

TEST(edit_bonus, P1AddTenSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_SEC1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->s1);
}

TEST(edit_bonus, P1AddSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_SEC2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->s2);
}

TEST(edit_bonus, P2AddHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_HOURS);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg1_val->h);
}

TEST(edit_bonus, P2AddTenMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MIN1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->m1);
}

TEST(edit_bonus, P2AddMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MIN2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->m2);
}

TEST(edit_bonus, P2AddTenSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->s1);
}

TEST(edit_bonus, P2AddSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->s2);
}

TEST(edit_bonus, EditNotDone)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC2);

    TEST_ASSERT_EQUAL(0, config_completed_fake.call_count);
}

TEST(edit_bonus, EditDone)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC2 + 1);

    TEST_ASSERT_EQUAL(1, config_completed_fake.call_count);
}

static void go_to_edit_state(const struct config_controller * edit, enum edit_state state)
{
    for (enum edit_state i = 0; i < state; i++)
    {
        edit->on_right();
    }
}
