#pragma once
#include <SFML/Graphics.hpp>

enum class character_type { undefined, Knight, Mage, Rogue };
enum class movement { IDLE, UP, LEFT, DOWN, RIGHT };
const int character_size_x = 15;
const int character_size_y = 27;

class Character
{
private:
	float scale;

	character_type type;

	sf::Texture Texture;
	sf::Vector2f position;
	sf::RectangleShape shape;

	void Create(character_type type, sf::Vector2f position);
public:
	Character();
	Character(character_type type);
	Character(character_type type, sf::Vector2f position);

	~Character();
	void change_character(character_type character);
	void move(movement direction, float frame);
	sf::RectangleShape getShape();
};

