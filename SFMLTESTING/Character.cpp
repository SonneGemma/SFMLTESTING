#include <iostream>
#include "Character.h"

void Character::Create(std::string file, sf::Vector2f position, float velocity)
{
	this->position = position;
	this->velocity = velocity;

	if (!Texture.loadFromFile(file)) std::cout << "Fail!";

	this->shape = sf::RectangleShape();
	this->shape.setSize(sf::Vector2f(character_size_x, character_size_y));

	this->shape.setTexture(&Texture);
	this->shape.setOrigin((character_size_x / 2), character_size_y);

	this->shape.setPosition(position);
	this->shape.setScale(scale, scale);
}

void Character::move(movement direction, float frame)
{
	//IDLE
	if (direction == movement::IDLE)
	{
		if (this->idleType == idle_type::STANDARD)
			this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 2), 0, character_size_x, character_size_y));
		else if (this->idleType == idle_type::JUMPING)
			this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 2), character_size_y * 2, character_size_x, character_size_y));
	}

	//WASD
	if (direction == movement::UP)
	{
		this->shape.move(0.0f, -this->velocity);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::DOWN)
	{
		this->shape.move(0.0f, +this->velocity);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::LEFT)
	{
		this->shape.move(-this->velocity, 0.0f);
		this->shape.setScale(-this->scale, this->scale);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::RIGHT)
	{
		this->shape.move(+this->velocity, 0.0f);
		this->shape.setScale(this->scale, this->scale);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}
}

void Character::change_idle_type(idle_type idleType)
{
	this->idleType = idleType;
}

sf::RectangleShape Character::getShape()
{
	return this->shape;
}