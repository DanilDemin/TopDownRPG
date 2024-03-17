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
    bool initAttack;
    bool attaking;
    Weapon* weapon;

    sf::Clock damageTimer;
    sf::Int32 damageTimerMax;



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
    const std::string toStringCharactertab() const;
    const bool& getInitAtack() const;
    const bool getDamageTimer();

    const unsigned getDamage() const;



    //Modifires
    void setInitAtack(const bool init_attack);



    //Functions
    void loseHp(const int hp);
    void gainHp(const int hp);
    void loseEXP(const int exp);
    void gainEXP(const int exp);


     
    void updateAnimation(const float& dt);
    void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

    void render(sf::RenderTarget& target, const bool show_hitbox = false);
};

