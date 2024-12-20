#include "stdafx.h"
#include "MeleeWeapon.h"

//Con / Des
MeleeWeapon::MeleeWeapon(unsigned level, unsigned damageMin, unsigned damageMax,
	unsigned range, unsigned value, std::string texture_file)
	: Weapon(level, damageMin, damageMax, range, value, texture_file)
{
	this->type = ItemTypes::IT_MELEEWEAPON;
}

MeleeWeapon::~MeleeWeapon()
{
	 
	std::cout << "delete MeleeWeapon" << "\n";
}

void MeleeWeapon::generate(const unsigned levelMin, const unsigned levelMax)
{
	this->level = rand() % (levelMax - levelMin + 1) + levelMin;

	this->damageMin = this->level * (rand() % 2 + 1);
	this->damageMin = this->level * (rand() % 2 + 1) + this->damageMin;

	this->range = this->level + rand() % 10 + 50;

	this->value = this->level + this->damageMin + this->damageMax + this->range + (rand() % level * 10);


	std::cout << "Level of Weapon: " << this->level << " " << this->damageMin << " " << this->damageMax <<  " " << this->range << " " <<  this->value << "\n";

}
