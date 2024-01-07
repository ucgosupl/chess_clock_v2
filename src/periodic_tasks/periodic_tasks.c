#include "periodic_tasks.h"

#include <stdlib.h>

#define CB_MAX	8

static periodic_cb_t cb_1ms[CB_MAX];
static periodic_cb_t cb_100ms[CB_MAX];

static uint32_t tick = 0;

static void call_all_1ms_callbacks(void);
static void call_all_100ms_callbacks(void);

void periodic_init(void)
{
	tick = 0;
}

void periodic_subscribe_1ms(periodic_cb_t cb)
{
	int i;

	for (i = 0; i < CB_MAX; i++)
	{
		if (cb_1ms[i] == NULL)
		{
			cb_1ms[i] = cb;
			break;
		}
	}
}

void periodic_subscribe_100ms(periodic_cb_t cb)
{
	int i;

	for (i = 0; i < CB_MAX; i++)
	{
		if (cb_100ms[i] == NULL)
		{
			cb_100ms[i] = cb;
			break;
		}
	}
}

void periodic_tick_1ms(void)
{
	call_all_1ms_callbacks();

	if (++tick >= 100)
	{
		tick = 0;
		call_all_100ms_callbacks();
	}
}

static void call_all_1ms_callbacks(void)
{
	for (int i = 0; i < CB_MAX; i++)
	{
		if (cb_1ms[i] != NULL)
		{
			cb_1ms[i]();
		}
		else
		{
			break;
		}
	}
}

static void call_all_100ms_callbacks(void)
{
	for (int i = 0; i < CB_MAX; i++)
	{
		if (cb_100ms[i] != NULL)
		{
			cb_100ms[i]();
		}
		else
		{
			break;
		}
	}
}
