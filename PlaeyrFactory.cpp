#include "stdafx.h"
#include "PlayerFactory.h"

PlayerFactory::PlayerFactory(const std::map<std::string, sf::Texture>& textures)
	: textures(textures)
{

}

PlayerFactory::~PlayerFactory()
{

}
