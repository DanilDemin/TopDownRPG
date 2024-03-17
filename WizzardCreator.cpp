#include "stdafx.h"
#include "WizzardCreator.h"

WizzardCreator::WizzardCreator(const std::map<std::string, sf::Texture>& _textures)
	: CharacterCreator(_textures)
{

}

WizzardCreator::~WizzardCreator()
{

}

Player* WizzardCreator::CreateCharacter()
{
	return new Wizzard(200, 200, this->textures["Player_Wizzard_Spritelist"]);
}
