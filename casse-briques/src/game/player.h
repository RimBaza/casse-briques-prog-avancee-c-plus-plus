#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SDL.h>

#include "../utils/defs.h"

#include "game_element.h"

class Player: public GameElement
{
	private: 
		int move_speed = 9;
		int lives_count;

		bool wings = false;

		int score = 0;

	public:
		Player(SDL_Renderer *renderer);

		int get_move_speed();
		void set_move_speed(int move_speed);

		int get_lives_count();
		void set_lives_count(int lives_count);
		void decrease_lives();
		bool is_alive();
		bool is_dead();

		bool has_wings();
		void set_wings(bool wings);

		int get_score();
		void set_score(int score);

		void set_middle_position(int x);
};

#endif