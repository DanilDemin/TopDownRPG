#include "stdafx.h"
#include "State.h"

State::State(StateData* state_data) 
	: stateData(state_data)
	, window(state_data->window)
	, supportedKeys(state_data->supportedKeys)
	, states(state_data->states)
	, quit(false)
	, paused(false)
	, keyTime(0.f)
	, keyTimeMax(10.f)
	, gridSize(state_data->gridSize)
{	

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

void State::updateMousePosition(sf::View* view)
{
	this->mousPosScreen = sf::Mouse::getPosition();
	this->mousPosWindow = sf::Mouse::getPosition(*this->window);


	if (view)
	{
		this->window->setView(*view);
	}


	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
	this->mousePosGrid = 
		sf::Vector2i(
			static_cast<int>(this->mousePosView.x) / static_cast<int>(this->gridSize),
			static_cast<int>(this->mousePosView.y) / static_cast<int>(this->gridSize)
		);


	this->window->setView(this->window->getDefaultView());
}

void State::updateKeytime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 100.f * dt;
	}
}
