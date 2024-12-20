#include "stdafx.h"
#include "EnemySystem.h"

EnemySystem::EnemySystem(std::vector<Enemy*>& activeEnemies,
	std::map<std::string, sf::Texture>& textures, Entity& player)
	: textures(textures)
	, activeEnemies(activeEnemies)
	, player(player)
{

}

EnemySystem::~EnemySystem()
{

}

void EnemySystem::createEnemy(short type,const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile)
{
	switch (type)
	{
	case EnemyTypes::SKELETON:
		this->activeEnemies.push_back(new Skeleton(xPos, yPos, this->textures["Skeleton_Spritelist"], enemy_spawner_tile, this->player));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	default:
		std::cout << "ERROR::ENEMYSYSTEM::CREATEENEMY::TYPE DOES NOT EXSIST" << "\n";
		break;
	}
}

void EnemySystem::removeEnemy(const int index)
{
	this->activeEnemies[index]->getEnemySpawnerTile().decreaseEnemyCounter();

	delete this->activeEnemies[index];
	this->activeEnemies.erase(this->activeEnemies.begin() + index);
}

void EnemySystem::update(const float& dt)
{

}

void EnemySystem::render(sf::RenderTarget* target)
{

}
