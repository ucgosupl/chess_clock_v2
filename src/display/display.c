#include "display.h"

#include "hd44780/hd44780.h"
#include <string.h>

static uint8_t lcd_buf[16 + 1] = "                ";

static const uint32_t config_blink_mapper[] =
{
	/*P1_HOURS,		*/ 0,
	/*P1_MIN1,		*/ 2,
	/*P1_MIN2,		*/ 3,
	/*P1_SEC1,		*/ 5,
	/*P1_SEC2,		*/ 6,

	/*P2_HOURS,		*/ 0 + 9,
	/*P2_MIN1,		*/ 2 + 9,
	/*P2_MIN2,		*/ 3 + 9,
	/*P2_SEC1,		*/ 5 + 9,
	/*P2_SEC2,		*/ 6 + 9,

	/*P1_INC_MIN,	*/ 6,
	/*P1_INC_SEC1,	*/ 8,
	/*P1_INC_SEC2,	*/ 9,

	/*P2_INC_MIN,	*/ 12,
	/*P2_INC_SEC1,	*/ 14,
	/*P2_INC_SEC2,	*/ 15,

	/*MOVES1,		*/ 7,
	/*MOVES2,		*/ 8,

	/*BONUS_HOURS,	*/ 7,
	/*BONUS_MIN1,	*/ 9,
	/*BONUS_MIN2,	*/ 10,
	/*BONUS_SEC1,	*/ 12,
	/*BONUS_SEC2,	*/ 13,
};

static const uint32_t edit_blink_mapper[] =
{
	/*P1_HOURS,		*/ 0,
	/*P1_MIN1,		*/ 2,
	/*P1_MIN2,		*/ 3,
	/*P1_SEC1,		*/ 5,
	/*P1_SEC2,		*/ 6,

	/*P2_HOURS,		*/ 0 + 9,
	/*P2_MIN1,		*/ 2 + 9,
	/*P2_MIN2,		*/ 3 + 9,
	/*P2_SEC1,		*/ 5 + 9,
	/*P2_SEC2,		*/ 6 + 9,

	/*P1_MOVES1,	*/ 8,
	/*P1_MOVES2,	*/ 9,

	/*P2_MOVES1,	*/ 14,
	/*P2_MOVES2,	*/ 15,
};
static void ms_to_string(ms_t ms, uint8_t *buf);
static void config_time_to_str(struct config_time *c, uint8_t *buf);
static void config_inc_to_str(struct config_time *c, uint8_t *buf);
static void config_blink(enum config_state state);
static void edit_blink(enum edit_state state);

void display_init(void)
{
	LCD_Init();
}

void display_show_mode(uint32_t mode)
{
	memcpy(lcd_buf, "MODE:           ", 16);
	lcd_buf[6] = mode / 10 + '0';
	lcd_buf[7] = mode % 10 + '0';
}

void display_show_time(ms_t p1, ms_t p2)
{
	memcpy(lcd_buf, "                ", 16);
	//h:mm.ss  h:mm:ss
	ms_to_string(p1, lcd_buf);
	ms_to_string(p2, lcd_buf + 9);
}

void display_show_config_time(struct config_time *p1, struct config_time *p2, enum config_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "                ", 16);

	config_time_to_str(p1, lcd_buf);
	config_time_to_str(p2, lcd_buf + 9);

	cnt++;
	if (cnt < 4)
	{
		config_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_config_inc(struct config_time *p1, struct config_time *p2, enum config_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "INC:            ", 16);

	config_inc_to_str(p1, lcd_buf + 6);
	config_inc_to_str(p2, lcd_buf + 12);

	cnt++;
	if (cnt < 4)
	{
		config_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_config_moves(struct config_moves *moves, enum config_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "MOVES:          ", 16);

	lcd_buf[7] = '0' + moves->moves1;
	lcd_buf[8] = '0' + moves->moves2;

	cnt++;
	if (cnt < 4)
	{
		config_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_config_bonus(struct config_time *bonus, enum config_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "BONUS:          ", 16);

	config_time_to_str(bonus, lcd_buf + 7);

	cnt++;
	if (cnt < 4)
	{
		config_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_edit_time(struct config_time *p1, struct config_time *p2, enum edit_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "                ", 16);

	config_time_to_str(p1, lcd_buf);
	config_time_to_str(p2, lcd_buf + 9);

	cnt++;
	if (cnt < 4)
	{
		edit_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_edit_moves(struct config_moves *p1, struct config_moves *p2, enum edit_state state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "MOVES:  xx    xx", 16);

	lcd_buf[8] = '0' + p1->moves1;
	lcd_buf[9] = '0' + p1->moves2;

	lcd_buf[14] = '0' + p2->moves1;
	lcd_buf[15] = '0' + p2->moves2;

	cnt++;
	if (cnt < 4)
	{
		edit_blink(state);
	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_update(void)
{
	LCD_SendCommand(0x80); // Set cursor to the beginning of the first line
	LCD_PrintString(lcd_buf);
}

static void ms_to_string(ms_t ms, uint8_t *buf)
{
	ms_t h = MS2H(ms);
	buf[0] = h + '0';
	ms %= MS_IN_H;

	ms_t m = MS2MIN(ms);
	buf[1] = ':';
	buf[2] = m / 10 + '0';
	buf[3] = m % 10 + '0';
	ms %= MS_IN_MIN;

	ms_t s = ms / MS_IN_S;
	buf[4] = '.';
	buf[5] = s / 10 + '0';
	buf[6] = s % 10 + '0';
}

static void config_time_to_str(struct config_time *c, uint8_t *buf)
{
	buf[0] = '0' + c->h;
	buf[1] = ':';
	buf[2] = '0' + c->m1;
	buf[3] = '0' + c->m2;
	buf[4] = '.';
	buf[5] = '0' + c->s1;
	buf[6] = '0' + c->s2;
}

static void config_inc_to_str(struct config_time *c, uint8_t *buf)
{
	buf[0] = '0' + c->m2;
	buf[1] = '.';
	buf[2] = '0' + c->s1;
	buf[3] = '0' + c->s2;
}

static void config_blink(enum config_state state)
{
	lcd_buf[config_blink_mapper[state]] = ' ';
}

static void edit_blink(enum edit_state state)
{
	lcd_buf[edit_blink_mapper[state]] = ' ';	
}