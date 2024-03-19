#pragma once

#include "EnemySpawnerTile.h"
#include "Skeleton.h"
#include "SkeletonFactory.h"
#include "OrcFactory.h"

enum EnemyTypes
{
	SKELETON = 0,
	SKELETON_WARRIOR,
	SKELETON_MAGE,
	SKELETON_ROGUE,
	ORC,
	ORC_WARRIOR,
	ORC_MAGE,
	ORC_ROGUE
};


class EnemySystem
{
private:
	EnemyFactory* skeletonFactory;
	EnemyFactory* orcFactory;

	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies, 
		std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	//Accessors


	//Modifiers


	//Functions
	void createEnemy(short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);

};

