#include "stdafx.h"
#include "OrcMage.h"

OrcMage::OrcMage(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Orc(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

OrcMage::~OrcMage()
{

}

void OrcMage::methodOfMage()
{
	std::cout << "OrcMageMethod" << '\n';
}
