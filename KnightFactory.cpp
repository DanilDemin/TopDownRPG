#include "stdafx.h"
#include "KnightFactory.h"

KnightFactory::KnightFactory(const std::map<std::string, sf::Texture>& textures)
	: PlayerFactory(textures)
{

}

KnightFactory::~KnightFactory()
{

}

Player* KnightFactory::createPlayer(float x, float y)
{
	return new Knight(x, y, this->textures["Player_Knight_Spritelist"]);
}
