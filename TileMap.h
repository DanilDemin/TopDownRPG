#pragma once
#include "EnemySpawnerTile.h"
#include "RegularTile.h"
#include "EnemiesInclude.h"
#include "EnemySystem.h"

class Tile;
class Entity;
class EnemySpawnerTile;
class Enemy;

class TileMap
{
private:

	void clear();

	float gridSizeF;
	int gridSizeI;
	sf::Vector2i maxSizeWorldGrid;
	sf::Vector2f maxSizeWorldF;
	int layers;
	std::vector< std::vector< std::vector< std::vector<Tile*> > > > map;
	std::stack<Tile*> deferredRenderStack;
	std::string textureFile;
	sf::Texture tileSheet;
	sf::Sprite tileSheetSprite;

	sf::RectangleShape collisionBox; 

	//Culling
	int fromX;
	int toX;
	int fromY;
	int toY;
	int layer;



public:
	//Con/Des
	TileMap(int gridSize, int width, int height, std::string texture_file);
	TileMap(const std::string file_name);
	virtual ~TileMap();

	//Accesors
	const bool tileEmpty(const int x, const int y, const int z) const;
	const sf::Texture* getTileSheet() const;
	const int getLayersSize(const int x, const int y, const int layer) const;
	
	const sf::Vector2i& getMaxSizeGrid() const;
	const sf::Vector2f& getMaxSizeWorldF() const;

 
	const sf::Sprite* getTileSpiteSheet() const;
	//Functoins

	void addTile(const int x, const int y, const int z, const sf::IntRect& texure_rect, const bool& collsion, const short& type);
	void addTile(const int x, const int y, const int z, const sf::IntRect& texure_rect,
		const int enemy_type, const int enemy_amount, const int enemy_tts, const int enemy_md);

	void removeTile(const int x, const int y, const int z, const int type);
	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name);

	const bool checkType(const int x, const int y, const int z, const int type) const;

 
	void updateWorldBoundsCollision(Entity* entity, const float& dt);
	void updateTileCollision(Entity* entity, const float& dt);
	void updateTiles(Entity* entity, const float& dt, EnemySystem& enemy_system);
	void update(Entity* entity, const float& dt);

	void render(sf::RenderTarget& target, const sf::Vector2i& gridPosition, const bool show_collision = false);
	void renderDeferred(sf::RenderTarget& rarget);

};

