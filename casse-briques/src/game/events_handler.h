#ifndef __EVENTS_H__
#define __EVENTS_H__

#include <SDL.h>
#include <iostream>

#include "../utils/defs.h"
#include "player.h"

class EventsHandler
{
	public :
		EventsHandler();
		bool handle_events(Player* player);
};

#endif