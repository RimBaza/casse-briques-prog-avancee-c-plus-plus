#include "ball.h"

Ball::Ball(SDL_Renderer *renderer) : GameElement(renderer)
{
	this->box = new SDL_Rect();
	this->color = new SDL_Color();

	this->speed = 15;
}

int Ball::get_speed()
{
	return this->speed;
}

void Ball::set_speed(int speed)
{
	this->speed = speed;
}

float Ball::get_vel_x()
{
	return this->vel_x;
}

void Ball::set_vel_x(float vel_x)
{
	this->vel_x = vel_x;
}

float Ball::get_vel_y()
{
	return this->vel_y;
}

void Ball::set_vel_y(float vel_y)
{
	this->vel_y = vel_y;
}

void Ball::translate(int dx, int dy)
{
	this->box->x += dx;
	this->box->y += dy;
}

void Ball::translate_x(int dx)
{
	this->box->x += dx;
}

void Ball::translate_y(int dy)
{
	this->box->y += dy;
}

void Ball::draw()
{
	//SDL_RenderFillRect( this->renderer, this->box );
	
	int radius = this->box->w / 2;
	SDLUtils::draw_circle( this->renderer, this->box->x + radius, this->box->y + radius, radius, *this->color);
}