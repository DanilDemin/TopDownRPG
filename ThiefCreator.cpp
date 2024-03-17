#include "stdafx.h"
#include "ThiefCreator.h"

ThiefCreator::ThiefCreator(const std::map<std::string, sf::Texture>& _textures)
	: CharacterCreator(_textures)
{

}

ThiefCreator::~ThiefCreator()
{

}

Player* ThiefCreator::CreateCharacter()
{
	return new Thief(200, 200, this->textures["Player_Thief_Spritelist"]);
}
