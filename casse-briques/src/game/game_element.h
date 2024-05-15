#ifndef __GAME_ELEMENT_H__
#define __GAME_ELEMENT_H__

#include <SDL.h>

class GameElement
{
	private:
		
	protected:
		SDL_Rect* box;
		SDL_Renderer *renderer;

	public:
		GameElement( SDL_Renderer *renderer ) {
			this->renderer = renderer;
		}

		SDL_Rect* get_box();

		int get_x();
		void set_x(int x);
		
		int get_y();
		void set_y(int y);

		void set_position(int x, int y);

		int get_width();
		void set_width(int width);

		int get_height();
		void set_height(int height);

		virtual void draw();
};

#endif