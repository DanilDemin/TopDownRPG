#pragma once
#include "CharacterCreator.h"
#include "Knight.h"

class KnightCreator :
    public CharacterCreator
{
private:
public:
    KnightCreator(const std::map<std::string, sf::Texture>& _textures);
    virtual ~KnightCreator();

    Player* CreateCharacter() override;

};

