#pragma once
#include "Weapon.h"
#include "HitboxComponent.h"

class MeleeWeapon :
    public Weapon
{
private:
    
protected:
    
public:
    //Con / Des
    MeleeWeapon(unsigned level, unsigned damageMin, unsigned damageMax,
        unsigned range, unsigned value, std::string texture_file);
    virtual ~MeleeWeapon() override;

     


    //Functions
    virtual MeleeWeapon* clone() = 0;
    virtual void generate(const unsigned levelMin, const unsigned levelMax) override;

    virtual void update(const sf::Vector2f& mousePosView, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};

