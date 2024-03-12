#pragma once

#include "EnemySpawnerTile.h"
#include "Skeleton.h"


enum EnemyTypes
{
	SKELETON = 0
};


class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies, 
		std::map<std::string, sf::Texture>& textures);
	virtual ~EnemySystem();

	//Accessors


	//Modifiers


	//Functions
	void createEnemy(short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);

};
