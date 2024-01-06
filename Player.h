#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:
    //Variables

    bool attacking;

    //Initializer function
    void initVariavles();
    void initComponetnt();
    
public:
    //Con/Des
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //Functions
    void updateAttack();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);

};

