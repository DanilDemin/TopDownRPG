#include "stdafx.h"
#include "EnemySpawnerTile.h"



//Con / Des
EnemySpawnerTile::EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
	const sf::Texture& texture, const sf::IntRect& texture_rect,
	int enemy_type, int enemy_amount, sf::Int32 enemy_time_to_spawn, int enemy_max_distance)
	: Tile(Tiletypes::ENEMYSPAWNER, grid_x, grid_y, gridSizeF, texture, texture_rect, false)
	, enemyType(enemy_type)
	, enemyAmount(enemy_amount)
	, enemyCounter(0)
	, enemyTimeToSpawn(enemy_time_to_spawn)
	, enemyMaxDistance(enemy_max_distance)
	, spawned(false)
{
	this->enemySpawnTimer.restart();
}

EnemySpawnerTile::~EnemySpawnerTile()
{

}

const std::string EnemySpawnerTile::getAsString() const
{
	/*
	* type,
	* x, y, z,(done in tilemap save)
	* rect x, rect y
	* enemy type,
	* enemy amount,
	* enemy time to spawn
	* enemy max distance
	* 
	*/
	std::stringstream ss;

	ss << this->type << " " << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " "
		<< "" <<  this->enemyType << " " <<  this->enemyAmount << " " <<  this->enemyTimeToSpawn << " " <<  this->enemyMaxDistance;

	std::cout << ss.str() << "\n";

	return ss.str();
}

const bool& EnemySpawnerTile::getSpawned() const
{
	return this->spawned;
}

const int& EnemySpawnerTile::getEnemyAmount() const
{
	return this->enemyAmount;
}

const int& EnemySpawnerTile::getEnemyCounter() const
{
	return this->enemyCounter;
}



void EnemySpawnerTile::SetSpawned(const bool spawned)
{
	this->spawned = spawned;
	this->enemySpawnTimer.restart();
}

const bool EnemySpawnerTile::canSpawn() const
{
	if (this->enemySpawnTimer.getElapsedTime().asMilliseconds() >= this->enemyTimeToSpawn)
	{
		return true;
	}
	return false;
}

void EnemySpawnerTile::increaseEnemyCounter()
{
	if (this->enemyCounter > this->enemyAmount)
	{
		this->enemyCounter = this->enemyAmount;
	}
	else
	{
		++this->enemyCounter;
	}
}

void EnemySpawnerTile::decreaseEnemyCounter()
{
	if (this->enemyCounter < 0)
	{
		this->enemyCounter = 0;
	}
	else
	{
		--this->enemyCounter;
	}
}

//Funtions

void EnemySpawnerTile::update()
{
	if (this->canSpawn())
	{
		this->spawned = false;
	}
}

void EnemySpawnerTile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
