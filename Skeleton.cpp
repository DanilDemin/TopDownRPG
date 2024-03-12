#include "stdafx.h"
#include "Skeleton.h"



//Initializer function
void Skeleton::initVariavles()
{
	this->scale = 6.f;
}


void Skeleton::initAnimation()
{
	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 3, 0, 32, 32);
	this->animationComponent->addAnimation("WALK", 5.f, 0, 1, 5, 1, 64, 32);
}

void Skeleton::initGUI()
{
	this->hpBar.setFillColor(sf::Color::Red);
	this->hpBar.setSize(sf::Vector2f(100.f, 20.f));
	this->hpBar.setPosition(this->sprite.getPosition());
}

//Con/Des
Skeleton::Skeleton(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile)
	: Enemy(enemy_spawner_tile)
{
	
	this->initVariavles();
	this->initGUI();


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

	this->generateAttributes(this->attributeComponent->level);

	this->setPosition(x, y);
	this->initAnimation();

}

Skeleton::~Skeleton()
{

}

void Skeleton::updateAnimation(const float& dt)
{


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


void Skeleton::update(const float& dt, sf::Vector2f& mouse_pos_view)
{
	this->movementComponent->update(dt);

	//GUI
	this->hpBar.setSize(sf::Vector2f(100.f * (static_cast<float>(this->attributeComponent->hp) / this->attributeComponent->hpMax), 20.f));
	this->hpBar.setPosition(this->sprite.getPosition());



	/*this->updateAttack();*/
	this->updateAnimation(dt);
	this->hitboxComponent->update();
}

void Skeleton::render(sf::RenderTarget& target, const bool show_hitbox)
{
	target.draw(this->sprite);

	if (show_hitbox)
	{
		this->hitboxComponent->render(target);
	}

	target.draw(this->hpBar);

}
