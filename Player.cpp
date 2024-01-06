#include "Player.h"

//Initializer function
void Player::initVariavles()
{
	this->attacking = false;
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

	//I shall should fix that scale * 7.f
	this->sprite.setScale(7.f, 7.f);

	//I shall should fix that scale * 7.f
	this->createHitboxComponent(this->sprite, 320.f, 335.f,
		245.f, 552.f);
	this->createMovementComponent(350.f, 10.f, 4.f);
	this->createAnimationComponent(texture_sheet);

	

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 5, 0, 128, 128);
	this->animationComponent->addAnimation("WALK", 12.f, 0, 1, 7, 1, 128, 128);
	this->animationComponent->addAnimation("ATTACK_1", 12.f, 0, 4, 4, 4, 128 , 128);
}

Player::~Player()
{
	 
}

//Functions
void Player::updateAttack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->attacking = true;
	}
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{	
		////Set origin depending of direction 
		//if (this->sprite.getScale().x < 0.f) //Facing left
		//{
		//	this->sprite.setOrigin(100.f, 0.f);
		//}
		//else //Facing right
		//{
		//	this->sprite.setOrigin(10.f, 0.f);
		//}


		//Animation and check animation end
		if (this->animationComponent->play("ATTACK_1", dt, true))
		{
			this->attacking = false;
		}
	}


	if (this->movementComponent->getState(IDLE))
	{
		this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{

		if (this->sprite.getScale().x < 0.f)
		{
			this->sprite.setOrigin(0.f, 0.f);
			this->sprite.setScale(7.f, 7.f);
		}

		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x,
			this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_LEFT))
	{

		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(126.f, 0.f);
			this->sprite.setScale(-7.f, 7.f);
		}

		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x,
			this->movementComponent->getMaxVelocity());
	}
}

void Player::update(const float& dt)
{	
	this->movementComponent->update(dt);
	this->updateAttack();
	this->updateAnimation(dt);
	this->hitboxComponent->update();
}
