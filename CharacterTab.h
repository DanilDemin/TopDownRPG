#pragma once
#include "Tab.h"

class CharacterTab : public Tab
{
private:
	sf::RectangleShape back;
	sf::Text infoText;
	


public:
	//Con / Des
	CharacterTab(sf::VideoMode& vm, sf::Font font, Player& player);
	virtual ~CharacterTab() override;

	//Fucntions
	void update() override;
	void render(sf::RenderTarget& target) override;
};

