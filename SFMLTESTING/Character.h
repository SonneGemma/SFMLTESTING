#pragma once
#include <SFML/Graphics.hpp>


enum class movement { IDLE, UP, LEFT, DOWN, RIGHT };
enum class idle_type { STANDARD, JUMPING };
const int character_size_x = 15;
const int character_size_y = 27;

class Character
{
protected:
	const float scale = 5;
	float velocity;

	idle_type idleType = idle_type::STANDARD;
	

	sf::Texture Texture;
	sf::Vector2f position;
	sf::RectangleShape shape;

	void Create(std::string file, sf::Vector2f position, float velocity);
public:

	void move(movement direction, float frame);
	void change_idle_type(idle_type idleType);

	sf::RectangleShape getShape();
};

