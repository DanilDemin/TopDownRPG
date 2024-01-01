#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:
    //Variables



    //Initializer function
    void initVariavles();
    void initComponetnt();
    
public:
    //Con/Des
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //Functions
    virtual void update(const float& dt);

};

