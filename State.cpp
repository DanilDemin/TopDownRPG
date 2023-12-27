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
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}


void State::endState()
{
	this->quit = true;
}

void State::updateMousePosition()
{
	this->mousPosScreen = sf::Mouse::getPosition();
	this->mousPosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
