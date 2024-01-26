#pragma once
enum movent_states {
	IDLE = 0,
	MOVING,
	MOVING_LEFT,
	MOVING_RIGHT
};

class MovementComponent
{
private:
	sf::Sprite& sprite;


	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;

	//Inirializer Functions


public:
	//Con/Des
	MovementComponent(sf::Sprite& sprite, float maxVelocity,
		float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accesors
	const float& getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;


	//Functions
	const bool getState(const short unsigned state) const;
	
	void move(const float dir_x, const float dir_y, const float dt);
	void update(const float& dt);

};

