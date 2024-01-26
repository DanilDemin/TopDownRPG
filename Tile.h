#pragma once

class Tile
{
private:


protected:
	sf::RectangleShape shape;

public:
	//Con/Des
	Tile();
	Tile(float x, float y, float gridSizeF);
	virtual ~Tile();

	//Functions
	void update();
	void render(sf::RenderTarget& target);

};

