#pragma once
#include "Player.h"
#include "Inventory.h"

class Knight :
    public Player
{
private:
    void initVariables(); 
    void initComponent();
    void initAnimation();
    void initInventory();



    
public:
    Knight(float x, float y, sf::Texture& texture_sheet);
    virtual ~Knight();
};

