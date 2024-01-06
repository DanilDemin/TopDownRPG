#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

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

