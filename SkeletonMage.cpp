#include "stdafx.h"
#include "SkeletonMage.h"

SkeletonMage::SkeletonMage(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Skeleton(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

SkeletonMage::~SkeletonMage()
{

}

void SkeletonMage::methodOfMage()
{
	std::cout << "SkeletoMageMethod" << '\n';
}
