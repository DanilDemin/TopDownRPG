#include "stdafx.h"
#include "KnightCreator.h"

KnightCreator::KnightCreator(const std::map<std::string, sf::Texture>& _textures)
	: CharacterCreator(_textures)
{

}

KnightCreator::~KnightCreator()
{

}

Player* KnightCreator::CreateCharacter()
{
	return new Knight(200, 200, this->textures["Player_Knight_Spritelist"]);
}
