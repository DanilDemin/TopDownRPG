#include "stdafx.h"
#include "ThiefFactory.h"

ThiefFactory::ThiefFactory(const std::map<std::string, sf::Texture>& textures)
	: PlayerFactory(textures)
{

}

ThiefFactory::~ThiefFactory()
{

}

Player* ThiefFactory::createPlayer(float x, float y)
{
	return new Thief(x, y, this->textures["Player_Thief_Spritelist"]);
}
