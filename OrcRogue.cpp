#include "stdafx.h"
#include "OrcRogue.h"
OrcRogue::OrcRogue(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Orc(x, y, texture_sheet, enemy_spawner_tile, player)
{

}

OrcRogue::~OrcRogue()
{

}

void OrcRogue::methodOfRogue()
{
	std::cout << "OrcRogueMethod" << '\n';
}
