#include "stdafx.h"
#include "OrcFactory.h"

OrcFactory::OrcFactory(const std::map<std::string, sf::Texture>& textures)
	: EnemyFactory(textures)
{
}

OrcFactory::~OrcFactory()
{

}

Enemy* OrcFactory::createBase(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new Orc(x, y, this->textures["Orc_Base_Spritelist"], enemy_spawner_tile, player);
}

Warrior* OrcFactory::createWarrior(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new OrcWarrior(x, y, this->textures["Orc_Warrior_Spritelist"], enemy_spawner_tile, player);
}

Mage* OrcFactory::createMage(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new OrcMage(x, y, this->textures["Orc_Mage_Spritelist"], enemy_spawner_tile, player);
}

Rogue* OrcFactory::createRogue(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
{
	return new OrcRogue(x, y, this->textures["Orc_Rogue_Spritelist"], enemy_spawner_tile, player);
}
