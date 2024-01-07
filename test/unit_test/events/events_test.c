#include "unity/fixture/unity_fixture.h"
#include "fff/fff.h"

#include "assert.h"

#include "events/events.h"

#include "buttons/buttons.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC0(bool, buttons_is_p1_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_p2_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_play_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_plus_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_minus_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_left_pressed);
FAKE_VALUE_FUNC0(bool, buttons_is_right_pressed);

TEST_GROUP(events);

TEST_SETUP(events)
{
    RESET_FAKE(buttons_is_p1_pressed);
    RESET_FAKE(buttons_is_p2_pressed);
    RESET_FAKE(buttons_is_play_pressed);
    RESET_FAKE(buttons_is_plus_pressed);
    RESET_FAKE(buttons_is_minus_pressed);
    RESET_FAKE(buttons_is_left_pressed);
    RESET_FAKE(buttons_is_right_pressed);
    FFF_RESET_HISTORY();

    events_init();
}

TEST_TEAR_DOWN(events)
{
    /* Cleanup after every test */
}

TEST(events, NoEvents)
{
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, EventPlus)
{
    buttons_is_plus_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(EVENT_BUTTON_PLUS, events_update());
}

TEST(events, EventPlusCooldown)
{
    buttons_is_plus_pressed_fake.return_val = true;

    events_update();
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, EventMinus)
{
    buttons_is_minus_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(EVENT_BUTTON_MINUS, events_update());
}

TEST(events, EventMinusCooldown)
{
    buttons_is_minus_pressed_fake.return_val = true;

    events_update();
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, EventLeft)
{
    buttons_is_left_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(EVENT_BUTTON_LEFT, events_update());
}

TEST(events, EventLeftCooldown)
{
    buttons_is_left_pressed_fake.return_val = true;

    events_update();
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, EventRight)
{
    buttons_is_right_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(EVENT_BUTTON_RIGHT, events_update());
}

TEST(events, EventRightCooldown)
{
    buttons_is_right_pressed_fake.return_val = true;

    events_update();
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, NoEventPlayIfStillPressed)
{
    buttons_is_play_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(0, events_update());
}

TEST(events, EventPlayAfterReleased)
{
    buttons_is_play_pressed_fake.return_val = true;
    events_update();

    buttons_is_play_pressed_fake.return_val = false;
    TEST_ASSERT_BIT_HIGH(EVENT_ID_PLAY, events_update());
}

TEST(events, SecondEventPlay)
{
    buttons_is_play_pressed_fake.return_val = true;
    events_update();

    buttons_is_play_pressed_fake.return_val = false;
    events_update();

    buttons_is_play_pressed_fake.return_val = true;
    TEST_ASSERT_EQUAL(0, events_update());

    buttons_is_play_pressed_fake.return_val = false;
    TEST_ASSERT_BIT_HIGH(EVENT_ID_PLAY, events_update());
}


TEST(events, EventEditAfterLongPress)
{
    buttons_is_play_pressed_fake.return_val = true;

    for(int i = 0; i < 31; i++)
    {
        events_update();
    }

    buttons_is_play_pressed_fake.return_val = false;
    TEST_ASSERT_BIT_HIGH(EVENT_ID_EDIT, events_update());
}
