#include "stdafx.h"
#include "AttributeComponent.h"

//Constructor Destructor
AttributeComponent::AttributeComponent(int level)
	: level(level)
	, exp(0)
	, expNext(static_cast<int>((50 / 3)* (pow(this->level + 1, 3)) -
		6 * pow(this->level + 1, 2) + ((this->level + 1) * 17 - 12)))
	, attributePoints(5)
	, vitality(1)
	, strength(1)
	, dexterity(1)
	, agility(1)
	, intelligence(1)
{
	//Stats
	this->updateLevel();
	this->updateStats(true);

}

AttributeComponent::~AttributeComponent()
{

}

//Functions

std::string AttributeComponent::debugPrint() const
{
	std::stringstream ss;
	ss << "Level: " << this->level << "\n"
		<< "Exp: " << this->exp << "\n"
		<< "ExpNext" << this->expNext << "\n"
		<< "Attp: " << this->attributePoints << "\n";


	return ss.str();
}

void AttributeComponent::loseHp(const int hp)
{
	this->hp -= hp;
	if (this->hp < 0) { this->hp = 0; }
}

void AttributeComponent::gainHp(const int hp)
{
	this->hp += hp;

	if (this->hp > this->hpMax)
	{
		this->hp = this->hpMax;
	}
}

void AttributeComponent::loseEXP(const int exp)
{
	this->exp -= exp;
	if (this->exp < 0) { this->exp = 0; }
}


void AttributeComponent::gainExp(const int exp)
{
	this->exp += exp;
	this->updateLevel();
}

const bool AttributeComponent::isDead() const
{
	return this->hp <= 0;
}


void AttributeComponent::updateStats(const bool reset)
{
	this->hpMax		= this->vitality * 5 + this->vitality + this->strength;
	this->damageMin = this->strength * 2 + this->strength / 4;
	this->damageMax = this->strength * 2 + this->strength / 2;
	this->accuracy	= this->dexterity * 5 + this->dexterity / 3;
	this->defence	= this->agility * 2 + this->agility / 4;
	this->luck		= this->intelligence * 2 + this->intelligence / 5;

	if (reset)
	{
		this->hp = this->hpMax;
	}
}

void AttributeComponent::updateLevel()
{
	while (this->exp >= this->expNext)
	{	
		++this->level;
		this->exp -= this->expNext;	

		this->expNext = static_cast<int>((50 / 3) * (pow(this->level, 3)) -
			6 * pow(this->level, 2) + (this->level * 17 - 12));

		++this->attributePoints;
	}
}

void AttributeComponent::update()
{
	this->updateLevel();
}
