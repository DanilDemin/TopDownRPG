#pragma once
#include "Player.h"
class Wizzard :
    public Player
{
private:
    void initVariables();
    void initComponent();
    void initAnimation();
    void initInventory();




public:
    Wizzard(float x, float y, sf::Texture& texture_sheet);
    virtual ~Wizzard();
};

