#pragma once
#include "PlayerFactory.h"
class ThiefFactory :
    public PlayerFactory
{
private:
public:
    ThiefFactory(const std::map<std::string, sf::Texture>& textures);
    virtual ~ThiefFactory();

    Player* createPlayer(float x, float y) override;
};

