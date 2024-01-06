#include "State.h"

State::State
	(
	sf::RenderWindow* window,
	std::map<std::string, int>* supportedKeys,
	std::stack<State*>* states
	) :
	window(window), supportedKeys(supportedKeys), states(states)
{	
	this->quit = false;
	this->paused = false();
	this->keyTime = 0.f;
	this->keyTimeMax = 10.f;
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
}

void State::updateKeytime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 100.f * dt;
	}
}
