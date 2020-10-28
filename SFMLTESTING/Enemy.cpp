#include "Enemy.h"

//TODO: llenar
std::map<enemy_type, std::string> Enemy::enemyTextures =
{
	{ enemy_type::Undefined, "" },
	{ enemy_type::Cry, "" },
	{ enemy_type::Boar, "" },
	{ enemy_type::Red, "" },
	{ enemy_type::Fungus, "" },
	{ enemy_type::NormGoop, "" },
	{ enemy_type::VenomGoop, "" },
	{ enemy_type::NormZombie, "" },
	{ enemy_type::IceZombie, "" },
	{ enemy_type::Killer, "" },
	{ enemy_type::BigBoar, "" },
	{ enemy_type::Trival, "" },
	{ enemy_type::DarkMage, "" },
	{ enemy_type::Ribs, "" },
	{ enemy_type::Demon, "" },
	{ enemy_type::Angel, "" }
};

Enemy::~Enemy()
{

}

Enemy::Enemy(enemy_type type)
{
	this->type = type;
	Enemy::Create(Enemy::enemyTextures[type], sf::Vector2f{ 200, 200 }, 5.0f);
}

Enemy::Enemy(enemy_type type, sf::Vector2f position)
{
	this->type = type;
	Enemy::Create(Enemy::enemyTextures[type], position, 5.0f);
}

Enemy::Enemy(enemy_type type, sf::Vector2f position, float velocity)
{
	this->type = type;
	Enemy::Create(Enemy::enemyTextures[type], position, velocity);
}