#include "stdafx.h"
#include "Player.h"

//Initializer function
void Player::initVariavles()
{
	/*this->attacking = false;
	this->scale = 6.f;
	this->sword = new Sword(20);*/

	/*this->inventory = new Inventory(100);*/
	this->weapon->generate(1, 3);

	this->damageTimer.restart();
}

void Player::initComponetnt()
{
	
}

void Player::initAnimation()
{
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 32, 32);
	this->animationComponent->addAnimation("WALK", 5.f, 0, 1, 5, 1, 64, 32);
}

void Player::initInventory()
{
	/*this->inventory = new Inventory(100);*/
}

//Con/Des
Player::Player(float x, float y, sf::Texture& texture_sheet)
	: attacking(false)
	, scale(6.f)
	, weapon(new Sword(1, 2, 5, 60, 20, "Resources/Images/Sprites/Weapon/Bone/Sword.png"))
	, inventory(new Inventory(100))
	, initAttack(false)
	, damageTimerMax(500)

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
	delete this->weapon;
}

//Accessors
AttributeComponent* Player::getAttributecomponent()
{
	return this->attributeComponent;
}

Weapon* Player::getWeapon() const
{
	return this->weapon;
}

const std::string Player::toStringCharactertab() const
{
	std::stringstream ss;
	AttributeComponent* ac = this->attributeComponent;
	Weapon* w = this->weapon;
	
	ss << "Level: " << ac->level << "\n"
		<< "Exp: " << ac->exp << "\n"
		<< "Exp next: " << ac->expNext << "\n"

		<< "Weapon Level: " << w->getLevel() << "\n"
		<< "Weapon Type: " << w->getType() << "\n"
		<< "Weapon Value: " << w->getValue() << "\n"
		<< "Weapon Range: " << w->getRange() << "\n"
		<< "Weapon Damage Min: " << w->getDamgeMin() + this->attributeComponent->damageMin << " (" << this->attributeComponent->damageMin << ")" << "\n"
		<< "Weapon Damage Max: " << w->getDamageMax() + this->attributeComponent->damageMax << " (" << this->attributeComponent->damageMax << ")" << "\n";

	return ss.str();
}

const bool& Player::getInitAtack() const
{
	return this->initAttack;
}

const bool Player::getDamageTimer()
{
	if (this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax)
	{
		this->damageTimer.restart();
		return true;
	}

	return false;
}

const unsigned Player::getDamage() const
{
	return rand() % (
		this->attributeComponent->damageMax + this->weapon->getDamageMax()
		- this->attributeComponent->damageMin + this->weapon->getDamgeMin() + 1)
		+ (this->attributeComponent->damageMin + this->weapon->getDamgeMin());
}

void Player::setInitAtack(const bool init_attack)
{
	this->initAttack = init_attack;
}

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

void Player::update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{	 
	this->movementComponent->update(dt);
	 
	this->updateAnimation(dt);
	this->hitboxComponent->update();

	this->weapon->update(mouse_pos_view, this->getCenter());
}

void Player::render(sf::RenderTarget& target, const bool show_hitbox)
{
	target.draw(this->sprite);
	
	if (show_hitbox)
	{
		this->hitboxComponent->render(target);
	}

	this->weapon->render(target);
}
