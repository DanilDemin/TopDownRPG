#include "stdafx.h"
#include "HitboxComponent.h"

//Con/Des


HitboxComponent::HitboxComponent(sf::Sprite& sprite,
	float offset_x, float offset_y,
	float width, float height)
	: sprite(sprite), offSetX(offset_x), offSetY(offset_y), width(width), height(height)
{
	this->nextPosition.left = 0.f;
	this->nextPosition.top = 0.f;
	this->nextPosition.width = width;
	this->nextPosition.height = height;
	


	this->hitbox.setPosition(this->sprite.getPosition().x + offset_x,
		this->sprite.getPosition().y + offset_y);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(-1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);

}

HitboxComponent::~HitboxComponent()
{

}

//Accessors
const sf::Vector2f& HitboxComponent::getPosition() const
{
	return this->hitbox.getPosition();
}

const sf::FloatRect HitboxComponent::getGlobalBounds() const
{
	return this->hitbox.getGlobalBounds();
}

const sf::FloatRect& HitboxComponent::getNextPosition(const sf::Vector2f& velocity)
{
	this->nextPosition.left = this->hitbox.getPosition().x + velocity.x;
	this->nextPosition.top = this->hitbox.getPosition().y + velocity.y;
	
	return this->nextPosition;
}

const float& HitboxComponent::getWidth() const
{
	return this->width;
}

const float& HitboxComponent::getHeight() const
{
	return this->height;
}

//Modifiers
void HitboxComponent::setPosition(const sf::Vector2f& position)
{

	this->hitbox.setPosition(position);

	this->sprite.setPosition(
		position.x - this->offSetX,
		position.y - this->offSetY
	);
}


void HitboxComponent::setPosition(const float x, const float y)
{
	this->hitbox.setPosition(x, y);

	this->sprite.setPosition(
		x - this->offSetX,
		y - this->offSetY
	);
}

//Functions
bool HitboxComponent::intersect(const sf::FloatRect& frect)
{
	return this->hitbox.getGlobalBounds().intersects(frect);
}


void HitboxComponent::update()
{
	this->hitbox.setPosition(
		this->sprite.getPosition().x + this->offSetX,
		this->sprite.getPosition().y + this->offSetY
	);
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}


