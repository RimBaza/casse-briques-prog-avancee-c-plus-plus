#ifndef __BRICK_H__
#define __BRICK_H__

#include <iostream>
#include <vector>

#include <SDL.h>

#include "../utils/defs.h"

#include "game_element.h"

class Brick: public GameElement
{
	private:
		int resistence;

		std::vector<SDL_Color> colors;

	public:
		Brick(SDL_Renderer *renderer);

		int get_resistence();
		void set_resistence(int resistence);
		
		bool exists();

		virtual void draw();
};

#endif