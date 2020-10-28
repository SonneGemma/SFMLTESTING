#pragma once
#include "Character.h"

enum class character_type { undefined, Knight, Mage, Rogue };

class Player : public Character
{
private:
	character_type type;
	static std::map<character_type, std::string> playerTextures;

public:
	Player();
	Player(character_type type);
	Player(character_type type, sf::Vector2f position);
	Player(character_type type, sf::Vector2f position, float velocity);

	void change_character(character_type character);
};

