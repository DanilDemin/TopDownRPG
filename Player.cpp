#include "Player.h"

//Initializer function
void Player::initVariavles()
{

}

void Player::initComponetnt()
{
	
}

//Con/Des
Player::Player(float x, float y, sf::Texture& texture_sheet)
{	
	this->initVariavles();
	
	
	this->setTexture(texture_sheet);
	this->setPosition(x, y);

	this->createMovementComponent(350.f, 10.f, 4.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 5, 0, 128, 128);
	this->animationComponent->addAnimation("WALk_RIGHT", 20.f, 0, 1, 7, 1, 128, 128);
}

Player::~Player()
{
	 
}
//Functions
void Player::update(const float& dt)
{	
	this->movementComponent->update(dt);


	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE_RIGHT", dt);
	}
	else if(this->movementComponent->getState(MOVING_RIGHT))
	{
		this->animationComponent->play("WALk_RIGHT", dt);
	}
	
}
