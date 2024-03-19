#pragma once
#include "PlayerFactory.h"
#include "Knight.h"

class KnightFactory :
    public PlayerFactory
{
private:
public:
    KnightFactory(const std::map<std::string, sf::Texture>& textures);
    virtual ~KnightFactory();

    Player* createPlayer(float x, float y) override;
};

