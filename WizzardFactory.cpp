#include "stdafx.h"
#include "WizzardFactory.h"

WizzardFactory::WizzardFactory(const std::map<std::string, sf::Texture>& textures)
	: PlayerFactory(textures)
{

}

WizzardFactory::~WizzardFactory()
{

}

Player* WizzardFactory::createPlayer(float x, float y)
{
	return new Wizzard(x, y, this->textures["Player_Wizzard_Spritelist"]);
}
