#include "stdafx.h"
#include "Player.h"

//Initializer function
void Player::initVariavles()
{
	/*this->attacking = false;
	this->scale = 6.f;
	this->sword = new Sword(20);*/

	/*this->inventory = new Inventory(100);*/

	this->sword->generate(1, 3);
}

void Player::initComponetnt()
{
	
}

void Player::initAnimation()
{
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 32, 32);
	this->animationComponent->addAnimation("WALK", 5.f, 0, 1, 5, 1, 64, 32);
	/*this->animationComponent->addAnimation("ATTACK_1", 8.f, 0, 4, 4, 4, 128 , 128);*/
}

void Player::initInventory()
{
	/*this->inventory = new Inventory(100);*/
}

//Con/Des
Player::Player(float x, float y, sf::Texture& texture_sheet)
	: attacking(false)
	, scale(6.f)
	, sword(new Sword(1, 2, 5, 60, 20, "Resources/Images/Sprites/Player/sword.png"))
	, inventory(new Inventory(100))
{	
	this->initVariavles();
	
	this->setTexture(texture_sheet);
	 
	//Basic version
	//I shall should fix that scale * 7.f
	this->sprite.setScale(1.f * this->scale, 1.f * this->scale);

	//I shall should fix that scale * 7.f
	this->createHitboxComponent(this->sprite, 8.f * this->scale, 2.f * this->scale,
		16.f * this->scale, 30.f * this->scale);

	this->createMovementComponent(550.f, 1000.f, 400.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);
	this->createSkillComponent();
	this->setPosition(x, y);
	this->initAnimation();

	this->initInventory();
}

Player::~Player()
{
	delete this->inventory;
	delete this->sword;
}

//Accessors
AttributeComponent* Player::getAttributecomponent()
{
	return this->attributeComponent;
}

Weapon* Player::getWeapon() const
{
	return this->sword;
}

//const sf::Vector2f& Player::getCenter() const
//{
//	return sf::Vector2f(
//		this->hitboxComponent->getPosition().x + this->hitboxComponent->getWidth() / 2.f,
//		this->hitboxComponent->getPosition().y + this->hitboxComponent->getHeight() / 2.f
//	);
//}

//Functions
void Player::loseHp(const int hp)
{
	this->attributeComponent->loseHp(hp);
}

void Player::gainHp(const int hp)
{
	this->attributeComponent->gainHp(hp);
}

void Player::loseEXP(const int exp)
{
	this->attributeComponent->loseHp(exp);
}

void Player::gainEXP(const int exp)
{
	this->attributeComponent->gainExp(exp);
}

void Player::updateAnimation(const float& dt)
{
	if (this->attacking)
	{	
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
			this->sprite.setScale(1.f * this->scale, 1.f * this->scale);
		}

		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x,
			this->movementComponent->getMaxVelocity());
	}

	else if (this->movementComponent->getState(MOVING_LEFT))
	{

		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(32.f, 0.f);
			this->sprite.setScale(-1.f * this->scale, 1.f * this->scale);
		}

		this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x,
			this->movementComponent->getMaxVelocity());
	}
}

void Player::update(const float& dt, sf::Vector2f& mouse_pos_view)
{	 
	this->movementComponent->update(dt);
	 
	this->updateAnimation(dt);
	this->hitboxComponent->update();

	this->sword->update(mouse_pos_view, this->getCenter());
}

void Player::render(sf::RenderTarget& target, const bool show_hitbox)
{
	target.draw(this->sprite);
	
	if (show_hitbox)
	{
		this->hitboxComponent->render(target);
	}

	this->sword->render(target);
}
