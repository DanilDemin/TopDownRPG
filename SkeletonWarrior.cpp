#include "stdafx.h"
#include "SkeletonWarrior.h"

SkeletonWarrior::SkeletonWarrior(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Skeleton(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

SkeletonWarrior::~SkeletonWarrior()
{

}

void SkeletonWarrior::methodOfWarrior()
{
	std::cout << "SkeletonWarriorMethod" << '\n';
}
