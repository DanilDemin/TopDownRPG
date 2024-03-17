#pragma once
#include "Knight.h"
#include "Wizzard.h"
#include "Thief.h"


class CharacterCreator
{
protected:
	//Resources
	std::map<std::string, sf::Texture> textures;


public:
	CharacterCreator(const std::map<std::string, sf::Texture>& _textures);
	~CharacterCreator();

	//Functions
	virtual Player* CreateCharacter() = 0;

};

