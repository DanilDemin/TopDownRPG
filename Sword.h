#pragma once
#include "MeleeWeapon.h"
class Sword :
    public MeleeWeapon
{
private:

public:
    //Con / Des
    Sword(unsigned level, unsigned damageMin, unsigned damageMax,
        unsigned range, unsigned value, std::string texture_file);
    virtual ~Sword() override;

    virtual Sword* clone() override;


    virtual void update(const sf::Vector2f& mousePosView, const sf::Vector2f center) override;
    virtual void render(sf::RenderTarget& target) override;
};

