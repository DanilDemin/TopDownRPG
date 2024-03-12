#include "stdafx.h"
#include "Bow.h"

//Con / Des
Bow::Bow(unsigned level, unsigned value, std::string texture_file)
	: RangedWeapon(level, value, texture_file)
{
	std::cout << "Bow" << "\n";
}

Bow::~Bow()
{
	std::cout << "delete Bow" << "\n";
}


//Functions
Bow* Bow::clone()
{
	return new Bow(*this);
}

void Bow::update(const sf::Vector2f& mousePosView, const sf::Vector2f center)
{

}

void Bow::render(sf::RenderTarget& target)
{

}
