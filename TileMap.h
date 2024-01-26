#pragma once

#include "Tile.h"

class TileMap
{
private:
	float gridSizeF;
	unsigned gridSizeU;
	sf::Vector2u maxSize;
	unsigned layers;
	std::vector< std::vector< std::vector<Tile*> > > map;
public:
	//Con/Des
	TileMap(float gridSize, unsigned width, unsigned height);
	virtual ~TileMap();

	//Functoins
	void update();
	void render(sf::RenderTarget& target);

	void addTile(const unsigned x, const unsigned y, const unsigned z);
	void removeTile();

};

