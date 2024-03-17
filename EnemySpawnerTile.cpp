#include "stdafx.h"
#include "EnemySpawnerTile.h"



//Con / Des
//WRONG CONSRTICTOE CAN NOT BEING TILE() WITH INIT LIST AFTER : `````````````````````````````````````````````````````````` REMOVE THAT
EnemySpawnerTile::EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
	const sf::Texture& texture, const sf::IntRect& texture_rect,
	int enemy_type, int enemy_amount, sf::Int32 enemy_time_to_spawn, int enemy_max_distance)
	: Tile(Tiletypes::ENEMYSPAWNER, grid_x, grid_y, gridSizeF, texture, texture_rect, false)
	, enemyType(enemy_type)
	, enemyAmount(enemy_amount)
	, enemyCounter(0)
	, enemyTimeToSpawn(enemy_time_to_spawn)
	, enemyMaxDistance(enemy_max_distance)
	, firstSpawn(true)
{
	this->enemySpawnTimer.restart();
}

EnemySpawnerTile::~EnemySpawnerTile()
{

}

const std::string EnemySpawnerTile::getAsString() const
{
	std::stringstream ss;

	ss << this->type << " " << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " "
		<< "" <<  this->enemyType << " " <<  this->enemyAmount << " " <<  this->enemyTimeToSpawn << " " <<  this->enemyMaxDistance;

	std::cout << ss.str() << "\n";

	return ss.str();
}


const int& EnemySpawnerTile::getEnemyAmount() const
{
	return this->enemyAmount;
}

const int& EnemySpawnerTile::getEnemyCounter() const
{
	return this->enemyCounter;
}

//?????????????????????????????????????????????????????????????????????? or something
const bool EnemySpawnerTile::getSpawnTimer()
{
	if (this->enemySpawnTimer.getElapsedTime().asSeconds() >= this->enemyTimeToSpawn || this->firstSpawn)
	{
		this->enemySpawnTimer.restart();
		this->firstSpawn = false;
		return true;
	}
	return false;
}

void EnemySpawnerTile::increaseEnemyCounter()
{
	if (this->enemyCounter <  this->enemyAmount)
		++this->enemyCounter;
	
}

void EnemySpawnerTile::decreaseEnemyCounter()
{
	if (this->enemyCounter > 0)
		--this->enemyCounter;
}

//Funtions

void EnemySpawnerTile::update()
{
	
}

void EnemySpawnerTile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
