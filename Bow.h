#pragma once
#include "RangedWeapon.h"

class RangedWeapon;

class Bow :
    public RangedWeapon
{
private:

public:
    //Con / Des
    Bow(unsigned level, unsigned value, std::string texture_file);
    virtual ~Bow() override;

    //Functions
    virtual Bow* clone() override;

    virtual void update(const sf::Vector2f& mousePosView, const sf::Vector2f center) override;
    virtual void render(sf::RenderTarget& target) override;
};

