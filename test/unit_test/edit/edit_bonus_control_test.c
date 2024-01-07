#include "unity/fixture/unity_fixture.h"

#include "assert.h"

#include "mode/mode.h"
#include "display_mocks.h"

static void go_to_edit_state(const struct config_controller * edit, enum edit_state state);

TEST_GROUP(edit_bonus_control);

TEST_SETUP(edit_bonus_control)
{
    RESET_FAKE(display_show_edit_time);
    RESET_FAKE(display_show_edit_moves);
    RESET_FAKE(config_completed);
    FFF_RESET_HISTORY();

    mode_set(BONUSC_CUSTOM);

    const struct mode_builder * mode_builder = mode_builder_get();
    mode_builder->init();
    mode_builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 0, 0));
    mode_builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 0));
    mode_builder->set_moves(PLAYER_BOTH, 30);

    const struct game_controller *game = mode_game_controller_get();
    game->on_move(PLAYER1);
    game->on_move(PLAYER2);
    game->on_move(PLAYER1);

    const struct config_controller * edit = mode_edit_controller_get();
    edit->on_entry(config_completed);
}

TEST_TEAR_DOWN(edit_bonus_control)
{
    /* Cleanup after every test */
}

TEST(edit_bonus_control, P1AddHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus_control, P1SubtractHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_plus();
    edit->on_minus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus_control, P1SubtractHourBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_minus();
    edit->on_minus();
    edit->display();

    TEST_ASSERT_EQUAL(0, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus_control, P1AddHourBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    for (int i = 0; i < 10 - 1; i++)
    {
        edit->on_plus();
    }
    
    edit->display();

    TEST_ASSERT_EQUAL(9, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus_control, P1LeftBounds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    edit->on_left();
    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg0_val->h);
}

TEST(edit_bonus_control, P1AddTenMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MIN1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->m1);
}

TEST(edit_bonus_control, P1AddMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MIN2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->m2);
}

TEST(edit_bonus_control, P1AddTenSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_SEC1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->s1);
}

TEST(edit_bonus_control, P1AddSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_SEC2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg0_val->s2);
}

TEST(edit_bonus_control, P2AddHours)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_HOURS);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_time_fake.arg1_val->h);
}

TEST(edit_bonus_control, P2AddTenMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MIN1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->m1);
}

TEST(edit_bonus_control, P2AddMinutes)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MIN2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->m2);
}

TEST(edit_bonus_control, P2AddTenSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->s1);
}

TEST(edit_bonus_control, P2AddSeconds)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_SEC2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_time_fake.arg1_val->s2);
}

TEST(edit_bonus_control, P1AddTenMoves)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MOVES1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_moves_fake.arg0_val->moves1);
}

TEST(edit_bonus_control, P1AddMoves)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P1_MOVES2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(3, display_show_edit_moves_fake.arg0_val->moves2);
}

TEST(edit_bonus_control, P2AddTenMoves)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MOVES1);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(1, display_show_edit_moves_fake.arg1_val->moves1);
}

TEST(edit_bonus_control, P2AddMoves)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_P2_MOVES2);

    edit->on_plus();
    edit->display();

    TEST_ASSERT_EQUAL(2, display_show_edit_moves_fake.arg1_val->moves2);
}

TEST(edit_bonus_control, EditNotDone)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_DONE - 1);

    TEST_ASSERT_EQUAL(0, config_completed_fake.call_count);
}

TEST(edit_bonus_control, EditDone)
{
    const struct config_controller * edit = mode_edit_controller_get();

    go_to_edit_state(edit, EDIT_DONE);

    TEST_ASSERT_EQUAL(1, config_completed_fake.call_count);
}

static void go_to_edit_state(const struct config_controller * edit, enum edit_state state)
{
    for (enum edit_state i = 0; i < state; i++)
    {
        edit->on_right();
    }
}
