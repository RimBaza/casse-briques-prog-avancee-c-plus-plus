#include "brick.h"

Brick::Brick(SDL_Renderer *renderer) :  GameElement(renderer) 
{
	SDL_Color color1;
	color1.r = 255;
	color1.g = color1.b = 0;
	colors.push_back( color1 );

	SDL_Color color2;
	color2.g = 255;
	color2.r = color1.b = 0;
	colors.push_back( color2 );

	SDL_Color color3;
	color3.b = 255;
	color2.r = color1.g = 0;
	colors.push_back( color3 );

	this->box = new SDL_Rect();

	this->box->w=(WINDOW_WIDTH-(SPACING*COLS)) / COLS;
    this->box->h=22;

    this->resistence = 1;
}

int Brick::get_resistence()
{
	return this->resistence;
}

void Brick::set_resistence(int resistence)
{
	this->resistence = resistence;
}

bool Brick::exists()
{
	return (this->resistence > 0);
}

void Brick::draw()
{
	//SDL_RenderFillRect( this->renderer, this->box );
	
	/*int radius = this->box->w / 2;
	SDLUtils::draw_circle( this->renderer, this->box->x + radius, this->box->y + radius, radius, *this->color);*/

	if (!this->exists()){
		return;
	}

	int color_index = (this->resistence-1) % colors.size();
	SDL_Color color = colors.at( color_index );

	SDL_SetRenderDrawColor( this->renderer, color.r, color.g, color.b, 255 );
	SDL_RenderFillRect( this->renderer, this->get_box() );
}