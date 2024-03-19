#include "stdafx.h"
#include "EnemySystem.h"



EnemySystem::EnemySystem(std::vector<Enemy*>& activeEnemies,
	std::map<std::string, sf::Texture>& textures, Entity& player)
	: skeletonFactory(new SkeletonFactory(textures))
	, orcFactory(new OrcFactory(textures))
	, textures(textures)
	, activeEnemies(activeEnemies)
	, player(player)
{

}

EnemySystem::~EnemySystem()
{
	delete this->skeletonFactory;
	delete this->orcFactory;
}

void EnemySystem::createEnemy(short type,const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile)
{
	switch (type)
	{
	case EnemyTypes::SKELETON:
		this->activeEnemies.push_back((this->skeletonFactory->createBase(xPos, yPos, enemy_spawner_tile, this->player)));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::SKELETON_WARRIOR:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->skeletonFactory->createWarrior(xPos, yPos, enemy_spawner_tile, this->player))));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::SKELETON_ROGUE:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->skeletonFactory->createRogue(xPos, yPos, enemy_spawner_tile, this->player))));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::SKELETON_MAGE:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->skeletonFactory->createMage(xPos, yPos, enemy_spawner_tile, this->player))));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::ORC_WARRIOR:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->orcFactory->createWarrior(xPos, yPos, enemy_spawner_tile, this->player))));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::ORC_MAGE:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->orcFactory->createMage(xPos, yPos, enemy_spawner_tile, this->player))));
		enemy_spawner_tile.increaseEnemyCounter();
		break;
	case EnemyTypes::ORC_ROGUE:
		this->activeEnemies.push_back(dynamic_cast<Enemy*>((this->orcFactory->createRogue(xPos, yPos, enemy_spawner_tile, this->player))));
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
