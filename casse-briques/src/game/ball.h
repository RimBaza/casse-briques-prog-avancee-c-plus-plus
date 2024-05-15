#ifndef __BALL_H__
#define __BALL_H__

#include <SDL.h>

#include "../utils/sdl_utils.h"

#include "game_element.h"

class Ball : public GameElement
{
	private:
		SDL_Color* color;
		
		int speed;

		float vel_y, vel_x;

	public:
		Ball(SDL_Renderer *renderer);

		int get_speed();
		void set_speed(int speed);

		float get_vel_x();
		void set_vel_x(float vel_x);

		float get_vel_y();
		void set_vel_y(float vel_y);

		void translate(int dx, int dy);
		void translate_x(int dx);
		void translate_y(int dy);

		virtual void draw();
};

#endif