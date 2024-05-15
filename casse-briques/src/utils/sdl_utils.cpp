#include "sdl_utils.h"


void SDLUtils::SDL_write_str(SDL_Renderer* renderer, std::string text, int x, int y, TTF_Font* font, SDL_Color color, SDL_Rect box)
{
    
    SDL_Surface *surface;
    SDL_Texture *texture;

    const char* t = text.c_str();

    surface = TTF_RenderText_Solid(font, t, color);

    texture = SDL_CreateTextureFromSurface( renderer, surface );

    box.w = surface->w;
    box.h = surface->h;

    box.x = x - box.w;
    box.y = y - box.h;

    SDL_FreeSurface( surface );
    SDL_RenderCopy( renderer, texture, NULL, &box );

    SDL_DestroyTexture( texture );
}

void SDLUtils::delay(int time)
{
    SDL_Delay(time);
}

void SDLUtils::draw_circle(SDL_Renderer* renderer, int centreX, int centreY, int radius)
{
	const int diameter = (radius * 2);

	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = (tx - diameter);

	while (x >= y)
	{
		// Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

	  if (error <= 0)
	  {
	  	++y;
	  	error += ty;
	  	ty += 2;
	  }

	  if (error > 0)
	  {
	  	--x;
	  	tx += 2;
	  	error += (tx - diameter);
	  }
	}
}

void SDLUtils::draw_circle(SDL_Renderer *renderer, int centerX, int centerY, int radius, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}