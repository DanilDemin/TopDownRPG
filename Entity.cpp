#include "stdafx.h"
#include "Entity.h"

void Entity::initVariables()
{	
	this->hitboxComponent = NULL;
	this->movementComponent = NULL;
	this->animationComponent = NULL;
	this->attributeComponent = NULL;
	this->skillComponent = NULL;
}

//Con/Des
Entity::Entity()
{	
	this->initVariables();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
	delete this->attributeComponent;
	delete this->skillComponent;
}

//Component Functions
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);

	/*this->sprite.setScale(7.f, 7.f);*/
}

void Entity::createHitboxComponent(sf::Sprite& sprite,
	float offset_x, float offset_y,
	float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y,
		width, height);
}

void Entity::createMovementComponent(const float maxVelocity,
	const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity,
		acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::createAttributeComponent(const unsigned level)
{
	this->attributeComponent = new AttributeComponent(level);
}

void Entity::createSkillComponent()
{
	this->skillComponent = new SkillComponent();
}

void Entity::createAIComponent()
{

}


const sf::Vector2f& Entity::getPosition() const
{
	//Return hitbox body
	if (this->hitboxComponent)
	{
		return this->hitboxComponent->getPosition();
	}

	//Return sprite body
	return this->sprite.getPosition();
}

const sf::Vector2i& Entity::getGridPosition(const int gridSizeI) const
{
	//hitbox body
	if (this->hitboxComponent)
	{
		return sf::Vector2i(
			static_cast<int>(this->hitboxComponent->getPosition().x) / gridSizeI,
			static_cast<int>(this->hitboxComponent->getPosition().y) / gridSizeI
		);
	}

	//sprite body
	return sf::Vector2i(
		static_cast<int>(this->sprite.getPosition().x) / gridSizeI,
		static_cast<int>(this->sprite.getPosition().y) / gridSizeI
	);
}

const sf::FloatRect Entity::getGlobalBounds() const
{
	//hitbox body
	if (this->hitboxComponent)
	{
		return this->hitboxComponent->getGlobalBounds();
	}

	//sprite body
	return this->sprite.getGlobalBounds();
}

const sf::FloatRect Entity::getNextPositionBounds(const float& dt) const
{
	if (this->hitboxComponent && this->movementComponent)
	{
		return this->hitboxComponent->getNextPosition(this->movementComponent->getVelocity() * dt);
	}
	return sf::FloatRect(-1.f, -1.f, -1.f, -1.f);
}

const sf::Vector2f& Entity::getCenter() const
{

	if (this->hitboxComponent)
	{
		return sf::Vector2f
		(
			this->getPosition().x + this->getWidth() / 2.f,
			this->getPosition().y + this->getHeight() / 2.f
		);
	}
}

const float& Entity::getWidth() const
{
	if (this->hitboxComponent) { return this->hitboxComponent->getWidth(); }
	else { return this->sprite.getTexture()->getSize().x; }
}

const float& Entity::getHeight() const
{
	if (this->hitboxComponent) { return this->hitboxComponent->getHeight(); }
	else { return this->sprite.getTexture()->getSize().y; }
}


//Functions
void Entity::setPosition(const float x, const float y)
{
	//Set hitbox 
	if (this->hitboxComponent)
	{
		this->hitboxComponent->setPosition(x, y);
	}
	else
	{
		this->sprite.setPosition(x, y);
	}
}


void Entity::move(const float dir_x, const float dir_y, const float& dt)
{	
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt); // Sets velocity 
	}
	if (this->skillComponent)
	{
		this->skillComponent->gainEXP(SKILLS::ENDURANCE, 1);
		/*std::cout << this->skillComponent->getSkill(SKILLS::ENDURANCE) << "\n";*/
	}
		
}

void Entity::stopVelocity()
{
	if (this->movementComponent)
	{
		this->movementComponent->stopVelocity();
	}
}

void Entity::stopVelocityX()
{
	if (this->movementComponent)
	{
		this->movementComponent->stopVelocityX();
	}
}

void Entity::stopVelocitY()
{
	if (this->movementComponent)
	{
		this->movementComponent->stopVelocityY();
	}
}


const float Entity::getDistance(const Entity& entity) const
{
	float x_center = entity.getCenter().x;
	float y_center = entity.getCenter().y;


	/*std::cout << sqrt(pow(this->getCenter().x - entity.getCenter().x, 2) + sqrt(pow(this->getCenter().y - entity.getCenter().y, 2))) << "\n";*/
	 
	return static_cast<float>(sqrt(pow(this->getCenter().x - x_center, 2) + (pow(this->getCenter().y - y_center, 2))));
}

