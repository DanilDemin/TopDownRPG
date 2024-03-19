#include "stdafx.h"
#include "SkeletonRogue.h"

SkeletonRogue::SkeletonRogue(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Skeleton(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

SkeletonRogue::~SkeletonRogue()
{

}

void SkeletonRogue::methodOfRogue()
{
	std::cout << "SkeletonWarriorMethod" << '\n';
}