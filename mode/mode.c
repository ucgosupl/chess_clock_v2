#include "mode.h"

#include <stdlib.h>

static const struct mode_interface * mode_i = NULL;

const struct mode_interface * mode_interface_get(void)
{
	return mode_i;
}

void mode_interface_set(const struct mode_interface *i)
{
	mode_i = i;
}
