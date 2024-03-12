#pragma once
#include "Entity.h"
#include "Items.h"
#include "Inventory.h"


class Player :
    public Entity
{
private:
    //Variables
    Inventory* inventory;

    bool attacking;
    float scale;
    Sword* sword;
    //Initializer function
    void initVariavles();
    void initComponetnt();
    void initAnimation();
    void initInventory();
    
public:
    //Con/Des
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    //Accessors
    AttributeComponent* getAttributecomponent();
    Weapon* getWeapon() const;
    /*const sf::Vector2f& getCenter() const override;*/


    //Functions
    void loseHp(const int hp);
    void gainHp(const int hp);
    void loseEXP(const int exp);
    void gainEXP(const int exp);


     
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view);

    void render(sf::RenderTarget& target, const bool show_hitbox = false);
};

