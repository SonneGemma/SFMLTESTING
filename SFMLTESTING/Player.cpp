#include <iostream>
#include "Player.h"

std::map<character_type, std::string> Player::playerTextures =
{
	{ character_type::undefined, "" },
	{ character_type::Knight, "../SFMLTESTING/Characters/knight_char.png" },
	{ character_type::Mage, "../SFMLTESTING/Characters/wizard_char.png" },
	{ character_type::Rogue, "../SFMLTESTING/Characters/dino_char.png" }
};

Player::Player()
{
	this->type = character_type::undefined;
	Player::Create(playerTextures[character_type::undefined], sf::Vector2f{ 100, 100 }, 5.0f);
}

Player::Player(character_type type)
{
	this->type = type;
	Player::Create(playerTextures[type], sf::Vector2f{ 100, 100 }, 5.0f);
}

Player::Player(character_type type, sf::Vector2f position)
{
	this->type = type;
	Player::Create(playerTextures[type], position, 5.0f);
}

Player::Player(character_type type, sf::Vector2f position, float velocity)
{
	this->type = type;
	Player::Create(playerTextures[type], position, velocity);
}

void Player::change_character(character_type character)
{
	if (!Texture.loadFromFile(playerTextures[character])) std::cout << "Fail!";
}
