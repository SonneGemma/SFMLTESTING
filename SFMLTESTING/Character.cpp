#include <iostream>
#include "Character.h"

Character::Character()
{
	Character::Create(character_type::undefined, sf::Vector2f{ 100, 100 });
}

Character::Character(character_type type)
{
	Character::Create(type, sf::Vector2f { 100, 100 });
}

Character::Character(character_type type, sf::Vector2f position)
{
	Character::Create(type, position);
}

void Character::Create(character_type type, sf::Vector2f position)
{
	this->scale = 10;

	this->type = type;

	this->position = position;

	this->change_character(this->type);

	this->shape = sf::RectangleShape();
	this->shape.setSize(sf::Vector2f(character_size_x, character_size_y));

	this->shape.setTexture(&Texture);
	this->shape.setOrigin((character_size_x / 2), character_size_y);

	this->shape.setPosition(position);
	this->shape.setScale(scale, scale);
}

Character::~Character()
{

}

void Character::change_character(character_type character)
{
	switch (character)
	{
	case character_type::Knight:
		if (!Texture.loadFromFile("../SFMLTESTING/Characters/knight_char.png")) std::cout << "Fail!";
		break;
	case character_type::Mage:
		if (!Texture.loadFromFile("../SFMLTESTING/Characters/wizard_char.png")) std::cout << "Fail!";
		break;
	case character_type::Rogue:
		if (!Texture.loadFromFile("../SFMLTESTING/Characters/dino_char.png")) std::cout << "Fail!";
		break;
	case character_type::undefined:
		std::cout << "Undefined!";
		break;
	default:
		std::cout << "Fail!";
		break;
	}
}

void Character::move(movement direction, float frame)
{
	if (direction == movement::IDLE)
	this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 2), 0, character_size_x, character_size_y));

	//WASD
	if (direction == movement::UP)
	{
		this->shape.move((float)0.0, (float)-5.0);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::DOWN)
	{
		this->shape.move((float)0.0, (float)+5.0);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::LEFT)
	{
		this->shape.move((float)-5.0, (float)0.0);
		this->shape.setScale(-10, 10);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}

	if (direction == movement::RIGHT)
	{
		this->shape.move((float)+5.0, (float)0.0);
		this->shape.setScale(10, 10);
		this->shape.setTextureRect(sf::IntRect(character_size_x * ((int)frame % 4), character_size_y, character_size_x, character_size_y));
	}
}

sf::RectangleShape Character::getShape()
{
	return this->shape;
}