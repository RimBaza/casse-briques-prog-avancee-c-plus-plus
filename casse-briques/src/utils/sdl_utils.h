#ifndef __SDL_UTILS_H__
#define __SDL_UTILS_H__

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

class SDLUtils
{
	public:
		static void delay(int time);
		static void SDL_write_str(SDL_Renderer* renderer, std::string text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Rect box);

		static void draw_circle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
		static void draw_circle(SDL_Renderer *renderer, int centerX, int centerY, int radius, SDL_Color color);
};

#endif