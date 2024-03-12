#pragma once
#include "Weapon.h"

class Item;

class RangedWeapon :
    public Weapon
{
private:

protected:


public:
    //Con / Des
    RangedWeapon(unsigned level, unsigned value, std::string texture_file);
    virtual ~RangedWeapon() override;


    //Functions
    virtual  RangedWeapon* clone() = 0;
    virtual void generate(const unsigned levelMin, const unsigned lebvelMax) override;

    virtual void update(const sf::Vector2f& mousePosView, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};

