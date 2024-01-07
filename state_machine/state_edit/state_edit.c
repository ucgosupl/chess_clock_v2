#include "state_edit.h"

#include "mode/mode.h"

static enum state state;

static const struct config_controller *edit;

static void completed_cb(void)
{
	state = GAME;
}

static void edit_init(void)
{

}

void edit_on_entry(void)
{
	state = EDIT;

	edit = mode_edit_controller_get();

	edit->on_entry(completed_cb);
}

enum state edit_on_tick(events_t events)
{
	if (state != EDIT)
	{
		return state;
	}
	
	if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLUS))
	{
		edit->on_plus();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_MINUS))
	{
		edit->on_minus();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_LEFT))
	{
		edit->on_left();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_RIGHT))
	{
		edit->on_right();
	}
	else if (EVENT_IS_ACTIVE(events, EVENT_BUTTON_PLAY))
	{

	}
	else
	{

	}

	edit->display();

	return state;
}

void edit_on_exit(void)
{
	edit->on_exit();
}

static const struct state_interface state_edit = 
{
	edit_init,
	edit_on_entry,
	edit_on_tick,
	edit_on_exit,
};

const struct state_interface * state_edit_get(void)
{
	return &state_edit;
}