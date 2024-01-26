#include "stdafx.h"
#include "State.h"

State::State
	(
		StateData* state_data
	) :
	window(state_data->window), supportedKeys(state_data->supportedKeys), states(state_data->states)
{	
	this->stateData = state_data;
	this->quit = false;
	this->paused = false();
	this->keyTime = 0.f;
	this->keyTimeMax = 10.f;
	this->gridSize = state_data->gridSize;
}

State::~State()
{

}

//Accessors
const bool& State::getQuit() const
{
	return this->quit;
}

const bool State::getKeytime()
{	
	if (this->keyTime >= this->keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}


//Functions
void State::endState()
{
	this->quit = true;
}

void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
}

void State::updateMousePosition()
{
	this->mousPosScreen = sf::Mouse::getPosition();
	this->mousPosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	this->mousePosGrid = 
		sf::Vector2u(
			static_cast<unsigned>(this->mousePosView.x) / static_cast<unsigned>(this->gridSize),
			static_cast<unsigned>(this->mousePosView.y) / static_cast<unsigned>(this->gridSize)
		);
}

void State::updateKeytime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 100.f * dt;
	}
}
