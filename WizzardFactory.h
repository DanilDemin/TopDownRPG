#pragma once
#include "PlayerFactory.h"


class WizzardFactory :
    public PlayerFactory
{
private:
public:
    WizzardFactory(const std::map<std::string, sf::Texture>& textures);
    virtual ~WizzardFactory();

    Player* createPlayer(float x, float y) override;

};

