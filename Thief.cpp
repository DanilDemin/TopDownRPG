#include "stdafx.h"
#include "Thief.h"

void Thief::initVariables()
{

}

void Thief::initComponent()
{
}


void Thief::initAnimation()
{
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 32, 32);
	this->animationComponent->addAnimation("WALK", 5.f, 0, 1, 5, 1, 64, 32);
}

void Thief::initInventory()
{
}

Thief::Thief(float x, float y, sf::Texture& texture_sheet)
	: Player(x, y, texture_sheet)

{
	this->initVariables();
	this->initComponent();
	this->initAnimation();
}

Thief::~Thief()
{

}
