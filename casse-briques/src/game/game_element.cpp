#include "game_element.h"

SDL_Rect* GameElement::get_box()
{
	return this->box;
}

int GameElement::get_x()
{
	return this->box->x;
}

void GameElement::set_x(int x)
{
	this->box->x = x;
}

int GameElement::get_y()
{
	return this->box->y;
}

void GameElement::set_y(int y)
{
	this->box->y = y;
}



void GameElement::set_position(int x, int y)
{
	this->box->x = x;
	this->box->y = y;
}

int GameElement::get_width()
{
	return this->box->w;
}

void GameElement::set_width(int width)
{
	this->box->w = width;
}

int GameElement::get_height()
{
	return this->box->h;
}

void GameElement::set_height(int height)
{
	this->box->h = height;
}


void GameElement::draw()
{
	SDL_RenderFillRect( this->renderer, this->box );
}