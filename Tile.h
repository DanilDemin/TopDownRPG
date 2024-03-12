#pragma once

enum Tiletypes {
	DEFAULT = 0,
	DAMAGING,
	DOODAD,
	ENEMYSPAWNER
};

class Tile
{
private:


protected:
	sf::RectangleShape shape;
	bool collision;
	short type;

public:
	//Con/Des
	Tile();
	Tile(short type, int grid_x, int grid_y, float gridSizeF,const sf::Texture& texture, const sf::IntRect& texture_rect,
		const bool collision);
	

	virtual ~Tile();

	//Accessors
	virtual const bool& getCollision() const;
	const short& getType() const;


	//Functions
	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::FloatRect getGlobalBounds() const;
	virtual const bool intersects(const sf::FloatRect bounds) const;
	virtual const std::string getAsString() const = 0;

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;

};

