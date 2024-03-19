#include "stdafx.h"
#include "OrcWarrior.h"

OrcWarrior::OrcWarrior(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Orc(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

OrcWarrior::~OrcWarrior()
{

}

void OrcWarrior::methodOfWarrior()
{
	std::cout << "OrcWarriorMethod" << '\n';
}
