#pragma once
#include "CharacterCreator.h"
class ThiefCreator :
    public CharacterCreator
{
private:
public:
    ThiefCreator(const std::map<std::string, sf::Texture>& _textures);
    virtual ~ThiefCreator();

    Player* CreateCharacter() override;
};

