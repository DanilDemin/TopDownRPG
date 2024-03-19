#pragma once
#include "Knight.h"
#include "Wizzard.h"
#include "Thief.h"


class PlayerFactory
{
protected:
	//Resources
	std::map<std::string, sf::Texture> textures;


public:
	PlayerFactory(const std::map<std::string, sf::Texture>& textures);
	virtual ~PlayerFactory();

	//Functions
	virtual Player* createPlayer(float x, float y) = 0;
};

