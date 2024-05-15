#include "player.h"

Player::Player(SDL_Renderer *renderer) : GameElement(renderer)
{
	this->box = new SDL_Rect();
	this->move_speed = 10;
}

int Player::get_move_speed()
{
	return this->move_speed;
}

void Player::set_move_speed(int move_speed)
{
	this->move_speed = move_speed;
}

int Player::get_lives_count()
{
	return this->lives_count;
}

void Player::set_lives_count(int lives_count)
{
	this->lives_count = lives_count;
}

void Player::decrease_lives(){
	if (this->lives_count > 0)
	{
		this->lives_count--;
	}
}

bool Player::is_alive()
{
	return this->lives_count > 0;
}

bool Player::is_dead()
{
	return this->lives_count <= 0;
}

bool Player::has_wings()
{
	return this->wings;
}

void Player::set_wings(bool wings)
{
	this->wings = wings;
}

int Player::get_score()
{
	return this->score;
}

void Player::set_score(int score)
{
	this->score = score;
}

void Player::set_middle_position(int x)
{
	if (this->box->w / 2  + x  > WINDOW_WIDTH) 
	{
		this->box->x = WINDOW_WIDTH - this->box->w;
		return;
	}

	this->box->x = x - this->box->w / 2;
	if (this->box->y < 0)
	{
		this->box->y = 0;
	}
}