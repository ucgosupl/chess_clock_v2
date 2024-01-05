#include "display.h"

#include "hd44780/hd44780.h"
#include <string.h>

static uint8_t lcd_buf[16 + 1] = "                ";

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

void display_show_config_time(struct config_time *p1, struct config_time *p2, uint32_t state)
{
	static uint32_t cnt = 0;

	memcpy(lcd_buf, "                ", 16);

	config_time_to_str(p1, lcd_buf);
	config_time_to_str(p2, lcd_buf + 9);

	cnt++;
	if (cnt < 4)
	{
		switch(state)
		{
		case 0:
			lcd_buf[0] = ' ';
			break;
		case 1:
			lcd_buf[2] = ' ';
			break;
		case 2:
			lcd_buf[3] = ' ';
 			break;
		case 3:
			lcd_buf[5] = ' ';
			break;
		case 4:
			lcd_buf[6] = ' ';
			break;

		case 5:
			lcd_buf[0 + 9] = ' ';
			break;
		case 6:
			lcd_buf[2 + 9] = ' ';
			break;
		case 7:
			lcd_buf[3 + 9] = ' ';
			break;
		case 8:
			lcd_buf[5 + 9] = ' ';
			break;
		case 9:
			lcd_buf[6 + 9] = ' ';
			break;

		}

	}
	else
	{
		if (cnt >= 6)
		{
			cnt = 0;
		}
	}
}

void display_show_config_inc(struct config_time *p1, struct config_time *p2, uint32_t state)
{
	memcpy(lcd_buf, "INC:            ", 16);

	config_inc_to_str(p1, lcd_buf + 6);
	config_inc_to_str(p2, lcd_buf + 12);
}

void display_show_config_moves(struct config_moves *moves, uint32_t state)
{
	memcpy(lcd_buf, "MOVES:          ", 16);

	lcd_buf[7] = '0' + moves->moves1;
	lcd_buf[8] = '0' + moves->moves2;
}

void display_show_config_bonus(struct config_time *bonus, uint32_t state)
{
	memcpy(lcd_buf, "BONUS:          ", 16);

	config_time_to_str(bonus, lcd_buf + 7);
}

void display_update(void)
{
	LCD_SendCommand(0x80); // Set cursor to the beginning of the first line
	LCD_PrintString(lcd_buf);
}
