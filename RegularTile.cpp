#include "stdafx.h"
#include "RegularTile.h"



RegularTile::RegularTile(short type, int grid_x, int grid_y, float gridSizeF,
	const sf::Texture& texture, const sf::IntRect& texture_rect, bool collision)
	: Tile(type, grid_x, grid_y, gridSizeF, texture, texture_rect, collision)
{

}

RegularTile::~RegularTile()
{

}

const std::string RegularTile::getAsString() const
{
	std::stringstream ss;

	ss << this->type << " " << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " " << this->collision;

	return ss.str();
}

void RegularTile::update()
{

}

void RegularTile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
