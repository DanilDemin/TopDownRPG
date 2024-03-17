#include "stdafx.h"
#include "Enemy.h"
#include "Entity.h"

//Initializer function
void Enemy::initVariavles()
{
	/*this->gainExp = 10;
	this->damageTimerMax = 1000;
	this->despawnTimerMax = 1000;*/
}


void Enemy::initAnimation()
{
	 
}

//Con/Des
Enemy::Enemy(EnemySpawnerTile& enemy_spawner_tile)
	: enemySpawnerTile(enemy_spawner_tile)
	, gainExp(10)
	, damageTimerMax(1000)
	, despawnTimerMax(100)
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

const bool Enemy::getDamageTimeDone() const
{
	return this->gamageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax;
}

const bool Enemy::getRespawnTimerDone() const
{	
	return this->despawnTimer.getElapsedTime().asMilliseconds() >= this->despawnTimerMax;
}

void Enemy::resetDamageTimer()
{
	this->gamageTimer.restart();
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

void Enemy::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{	 
	if (vectorDistance(this->getPosition(), view.getCenter()) > 1000.f)
	{
		this->despawnTimer.restart();
	}
}


 