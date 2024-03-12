#include "stdafx.h"
#include "Enemy.h"

//Initializer function
void Enemy::initVariavles()
{
	this->gainExp = 10;
}


void Enemy::initAnimation()
{
	 
}

//Con/Des
Enemy::Enemy(EnemySpawnerTile& enemy_spawner_tile)
	: enemySpawnerTile(enemy_spawner_tile)
{
	this->initVariavles();
	this->initAnimation();
}

Enemy::~Enemy()
{

}

const AttributeComponent* Enemy::getAttributeComp() const
{
	if(this->attributeComponent){ return this->attributeComponent; }
	else 
	{
		std::cout << "The AtrubuteComponent does not exist" << "\n";
		return nullptr; 
	}
}

const unsigned& Enemy::getGainExp() const
{
	return this->gainExp;
}

EnemySpawnerTile& Enemy::getEnemySpawnerTile()
{
	return this->enemySpawnerTile;
}


void Enemy::generateAttributes(const unsigned level)
{
	this->gainExp = level * (rand() % 5 + 1);
}

const bool Enemy::isDead() const
{
	if (this->attributeComponent)
	{
		return this->attributeComponent->isDead();
	}

	return false;
}

void Enemy::loseHp(const int hp)
{
	if (this->attributeComponent)
	{
		this->attributeComponent->loseHp(hp);
	}
}


 