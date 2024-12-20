#include "stdafx.h"
#include "Weapon.h"

void Weapon::initVariables()
{
	this->range = 100;
	this->damageMin = 1;
	this->damageMax = 2;

	//Timer
	this->attackTimerMax = 300.f;
}

Weapon::Weapon(unsigned level, unsigned value, std::string texture_file)
	: Item(level, value)
{

	this->initVariables();


	if (!this->weapon_texture.loadFromFile(texture_file))
	{
		std::cout << "ERROR::PLAYER::COULD NOT LOAD WEAPON TEXTURE" << texture_file;
	}
	this->weapon_sprite.setTexture(this->weapon_texture);
}


//WRONG STYLE :: CONSTRUCTOR WITH INIT LIST!!!!!!!!!!!!!!!!!!1 rEMOVE THAT!!!!!!!!!!!!!!!!!!!!!!!!!!!!1 
Weapon::Weapon(unsigned level, unsigned damageMin, unsigned damageMax,
	unsigned range, unsigned value, std::string texture_file)
	: Item(level,value)
	, damageMin(damageMin)
	, damageMax(damageMax)
	, range(range)
	, attackTimerMax(300.f)
{
	this->attackTimer.restart();

	if (!this->weapon_texture.loadFromFile(texture_file))
	{
		std::cout << "ERROR::PLAYER::COULD NOT LOAD WEAPON TEXTURE" << texture_file;
	}
	this->weapon_sprite.setTexture(this->weapon_texture);
}


Weapon::~Weapon()
{

}

const unsigned& Weapon::getDamgeMin() const
{
	return this->damageMin;
}

const unsigned& Weapon::getDamageMax() const
{
	return this->damageMax;
}

const unsigned& Weapon::getDamage() const
{
	return rand() % (this->damageMax - this->damageMin + 1) + (this->damageMin);
}

const unsigned& Weapon::getRange() const
{
	return this->range;
}

const bool Weapon::getAttackTimer()
{
	std::cout << this->attackTimer.getElapsedTime().asMilliseconds() << "\n";

	if (this->attackTimer.getElapsedTime().asMilliseconds() >= this->attackTimerMax)
	{
		this->attackTimer.restart();
		return true;
	}
	return false;
}

