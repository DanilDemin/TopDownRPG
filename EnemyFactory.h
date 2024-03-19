#pragma once
#include "EnemiesInclude.h"

class EnemyFactory
{
protected:
	//Resources
	std::map<std::string, sf::Texture> textures;


public:
	EnemyFactory(const std::map<std::string, sf::Texture>& textures);
	virtual ~EnemyFactory();

	//Functions
	virtual Enemy* createBase(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) = 0;
	virtual Warrior* createWarrior(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) = 0;
	virtual Mage* createMage(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) = 0;
	virtual Rogue* createRogue(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) = 0;
};

