#include "unity/fixture/unity_fixture.h"

#include "assert.h"
#include <stdio.h>

#include "mode/mode.h"

TEST_GROUP(preset_modes_fixed);

TEST_SETUP(preset_modes_fixed)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(preset_modes_fixed)
{
    /* Cleanup after every test */
}

struct mode_params
{
    enum mode id;
    const char *name;
    ms_t start_time;
    ms_t increment;
    moves_t moves;
    ms_t bonus;
};

static const moves_t MOVES_NOT_USED = 0xFFFFFFFF;

static const struct mode_params mapper[] =
{
	{FIXED_1M, "FIXED_1M", TIME_TO_MS(0, 1, 0), 0, MOVES_NOT_USED, 0},
	{FIXED_5M, "FIXED_5M", TIME_TO_MS(0, 5, 0), 0, MOVES_NOT_USED, 0},
	{FIXED_15M, "FIXED_15M", TIME_TO_MS(0, 15, 0), 0, MOVES_NOT_USED, 0},
	{FIXED_30M, "FIXED_30M", TIME_TO_MS(0, 30, 0), 0, MOVES_NOT_USED, 0},
	{FIXED_1H, "FIXED_1H", TIME_TO_MS(1, 0, 0), 0, MOVES_NOT_USED, 0},
	{FIXED_1H_30M, "FIXED_1H_30M", TIME_TO_MS(1, 30, 0), 0, MOVES_NOT_USED, 0},

	{BONUS_1M_1S, "BONUS_1M_1S", TIME_TO_MS(0, 1, 0), TIME_TO_MS(0, 0, 1), MOVES_NOT_USED, 0},
	{BONUS_3M_2S, "BONUS_3M_2S", TIME_TO_MS(0, 3, 0), TIME_TO_MS(0, 0, 2), MOVES_NOT_USED, 0},
	{BONUS_5M_3S, "BONUS_5M_3S", TIME_TO_MS(0, 5, 0), TIME_TO_MS(0, 0, 3), MOVES_NOT_USED, 0},
	{BONUS_10M_5S, "BONUS_10M_5S", TIME_TO_MS(0, 10, 0), TIME_TO_MS(0, 0, 5), MOVES_NOT_USED, 0},
	{BONUS_15M_10S, "BONUS_15M_10S", TIME_TO_MS(0, 15, 0), TIME_TO_MS(0, 0, 10), MOVES_NOT_USED, 0},
	{BONUS_1H30M_30S, "BONUS_1H30M_30S", TIME_TO_MS(1, 30, 0), TIME_TO_MS(0, 0, 30), MOVES_NOT_USED, 0},

	{BONUSC_1H30M_30S_40MOV_30M, "BONUSC_1H30M_30S_40MOV_30M", TIME_TO_MS(1, 30, 0), TIME_TO_MS(0, 0, 30), 40, TIME_TO_MS(0, 30, 0)},

	{FIXEDC_1H30M_30MOV_1H, "FIXEDC_1H30M_30MOV_1H", TIME_TO_MS(1, 30, 0), 0, 30, TIME_TO_MS(1, 0, 0)},
};

static const size_t MAPPER_SIZE = sizeof(mapper)/sizeof(mapper[0]);
static const struct game_controller * game_setup(size_t i);
static void generate_error_message(char *str, size_t i);

TEST(preset_modes_fixed, TimeSet)
{
    const struct game_controller *game;
    char str[64] = "";

    for (size_t i = 0; i < MAPPER_SIZE; i++)
    {
        game = game_setup(i);
        generate_error_message(str, i);

        ms_t time_expected = mapper[i].start_time + mapper[i].increment;

        TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER1), str);
        TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER2), str);
    }
}

TEST(preset_modes_fixed, Increment)
{
    const struct game_controller *game;
    char str[64] = "";

    for (size_t i = 0; i < MAPPER_SIZE; i++)
    {
        game = game_setup(i);
        generate_error_message(str, i);
        
        game->on_move(PLAYER1);
        game->on_move(PLAYER2);

        ms_t time_expected = mapper[i].start_time + 2*mapper[i].increment;

        TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER1), str);
        TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER2), str);
    }
}

TEST(preset_modes_fixed, BonusTime)
{
    const struct game_controller *game;
    char str[64] = "";

    for (size_t i = 0; i < MAPPER_SIZE; i++)
    {
        game = game_setup(i);
        generate_error_message(str, i);

        if (mapper[i].moves != MOVES_NOT_USED)
        {
            for (moves_t j = 0; j < mapper[i].moves; j++)
            {
                game->on_move(PLAYER1);
                game->on_move(PLAYER2);
            }

            ms_t time_expected = mapper[i].start_time + (1 + mapper[i].moves) * mapper[i].increment + mapper[i].bonus;

            TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER1), str);
            TEST_ASSERT_EQUAL_UINT32_MESSAGE(time_expected, game->time_get(PLAYER2), str);
        }


    }
}
static const struct game_controller * game_setup(size_t i)
{
        mode_set(mapper[i].id);
        mode_config_controller_get();

        return mode_game_controller_get();
}

static void generate_error_message(char *str, size_t i)
{
    sprintf(str, "Failed on MODE: %d(\"%s\")", mapper[i].id, mapper[i].name);
}
