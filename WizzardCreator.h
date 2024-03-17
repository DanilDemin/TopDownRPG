#pragma once
#include "CharacterCreator.h"
class WizzardCreator :
    public CharacterCreator
{
private:
public:
    WizzardCreator(const std::map<std::string, sf::Texture>& _textures);
    virtual ~WizzardCreator();

    Player* CreateCharacter() override;

};

