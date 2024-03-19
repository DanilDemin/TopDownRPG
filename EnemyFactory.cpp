#include "stdafx.h"
#include "EnemyFactory.h"

EnemyFactory::EnemyFactory(const std::map<std::string, sf::Texture>& textures)
	: textures(textures)
{

}

EnemyFactory::~EnemyFactory()
{

}
