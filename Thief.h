#pragma once
#include "Player.h"
class Thief :
    public Player
{
private:
    void initVariables();
    void initComponent();
    void initAnimation();
    void initInventory();




public:
    Thief(float x, float y, sf::Texture& texture_sheet);
    virtual ~Thief();
};

