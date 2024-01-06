#include "MovementComponent.h"

//Con/Des
 
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
	float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity),
	acceleration(acceleration), deceleration(deceleration)

{
	 
}

MovementComponent::~MovementComponent()
{

}

//Accesors
const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
		{
			return true;
		}
		break;
	case MOVING:
		if (this->velocity.x != 0.f || this->velocity.y != 0.f)
		{
			return true;
		}
		break;
	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
		{
			return true;
		}
		break;
	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
		{
			return true;
		}
		break;

	}
	return false;
}



//Functions
void MovementComponent::move(const float dir_x, const float dir_y, const float dt)
{	
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{	
	// Move X
	if (this->velocity.x > 0.f) //Check for posive x
	{	
		//Max velocity check positive
		if (this->velocity.x > this->maxVelocity) { this->velocity.x = maxVelocity; }

		//Deceleration x positive
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f) { this->velocity.x = 0.f; }

	}
	else if (this->velocity.x < 0.f) //Check for negegative x
	{	

		//Max velocity check negative
		if (this->velocity.x < -this->maxVelocity) { this->velocity.x = -maxVelocity; }

		//Deceleration x negative
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f) { this->velocity.x = 0.f; }
	}

	// Move Y
	if (this->velocity.y > 0.f) //Check for posive y
	{
		//Max velocity check positive
		if (this->velocity.y > this->maxVelocity){ this->velocity.y = maxVelocity; }
		//Deceleration y positive
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f) { this->velocity.y = 0.f; }

	}
	else if (this->velocity.y < 0.f) //Check for negegative y
	{

		//Max velocity check negative
		if (this->velocity.y < -this->maxVelocity){ this->velocity.y = -maxVelocity; }

		//Deceleration y negative
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f) { this->velocity.y = 0.f; }
	}


	//Final move
	this->sprite.move(this->velocity * dt); //Uses velocity
}