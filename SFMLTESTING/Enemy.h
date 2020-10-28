#pragma once
#include "Character.h"

//completar
enum class enemy_type { Undefined, Cry, Boar, Red, Fungus, NormGoop, VenomGoop, NormZombie, IceZombie, Killer, BigBoar, Trival, DarkMage, Ribs, Demon, Angel };

class Enemy : public Character
{
private:

	enemy_type type;
	static std::map<enemy_type, std::string> enemyTextures;

public:
	Enemy(enemy_type);
	Enemy(enemy_type type, sf::Vector2f position);
	Enemy(enemy_type type, sf::Vector2f position, float velocity);

	~Enemy();
};

