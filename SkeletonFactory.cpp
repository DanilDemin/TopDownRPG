#include "stdafx.h"
#include "SkeletonFactory.h"

SkeletonFactory::SkeletonFactory(const std::map<std::string, sf::Texture>& textures)
	: EnemyFactory(textures)
{
}

SkeletonFactory::~SkeletonFactory()
{

}

Enemy* SkeletonFactory::createBase(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new Skeleton(x, y, this->textures["Skeleton_Base_Spritelist"], enemy_spawner_tile, player);
}

Warrior* SkeletonFactory::createWarrior(float x, float y,EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new SkeletonWarrior(x, y, this->textures["Skeleton_Warrior_Spritelist"], enemy_spawner_tile, player);
}

Mage* SkeletonFactory::createMage(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new SkeletonMage(x, y, this->textures["Skeleton_Mage_Spritelist"], enemy_spawner_tile, player);
}

Rogue* SkeletonFactory::createRogue(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new SkeletonRogue(x, y, this->textures["Skeleton_Rogue_Spritelist"], enemy_spawner_tile, player);
}
