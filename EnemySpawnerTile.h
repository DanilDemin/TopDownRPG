#pragma once
#include "Enemy.h"
#include "Tile.h"

class Entity;
class Enemy;

class EnemySpawnerTile
	: public Tile
{
private:
	sf::RectangleShape shape;


	//Variables
	sf::Vector2i gridPosition;

	int enemyType;
	int enemyAmount;
	int enemyCounter;



	sf::Clock enemySpawnTimer;
	sf::Int32 enemyTimeToSpawn;
	float enemyMaxDistance;
	bool spawned;

	//Spawn timer



public:
	//Con / Des
	EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		int enemy_type, int enemy_amount, sf::Int32 enemy_time_to_spawn, int enemy_max_distance);
	virtual ~EnemySpawnerTile() override;

	//Accessors
	virtual const std::string getAsString() const;
	const bool& getSpawned() const;
	const int& getEnemyAmount() const;
	const int& getEnemyCounter() const;	
	

	//Modifiers
	void SetSpawned(const bool spawned);


	//Funtions
	const bool canSpawn() const;
	void increaseEnemyCounter();
	void decreaseEnemyCounter();

	void update() override;
	void render(sf::RenderTarget& target) override;
};

