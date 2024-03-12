#pragma once
#include "CharacterTab.h"


class PlayerGUITabs
{
private:
	CharacterTab characterTab;

	//Core
	sf::VideoMode& vm;
	sf::Font font;
	Player& player;

	sf::Clock keyTimer;
	float keyTimeMax;

	//Private Functions
	void initKeyTime();

public:
	PlayerGUITabs(sf::VideoMode& vm, sf::Font font, Player& player);
	virtual ~PlayerGUITabs();

	//Accessors
	const bool getKeyTimre();
	const bool tabsOpen();

	void toggleCharacterTab();

	//Funtions
	void update();
	void render(sf::RenderTarget& target);


};

