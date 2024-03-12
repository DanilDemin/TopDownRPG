#pragma once
#include "PlayerGUITabs.h"

class Player;
class sf::RectangleShape;

class PlayerGUI
{
private:
	Player* player;


	sf::VideoMode& vm;
	sf::Font font;


	//Level bar
	std::string levelBarString;
	sf::Text levelBarText;
	sf::RectangleShape levelBarBack;

	//EXP bar
	gui::ProgressBar* expBar;
	//Hp bar
	gui::ProgressBar* hpBar;
	//PlayerGUITabs
	PlayerGUITabs* playerTabs;




	void initFont();
	void initLevelBar();
	void initHpBar();
	void initEXPBar();
	void initPlayerTabs(sf::VideoMode& vm, sf::Font& font, Player& player);


		
public:
	//Con Des
	PlayerGUI(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGUI();


	//Accessors
	const bool getTabsOpen() const;
	void toggleCharacterTab();

	//Functions
	void updateLevelbar();
	void updateEXPBar();
	void updateHpBar();
	void updatePlayerTabs();

	void update(const float& dt);;


	void renderLevelBar(sf::RenderTarget& target);
	void renderEXPBAR(sf::RenderTarget& target);
	void renderHpBar(sf::RenderTarget& target);
	void renderPlayerTabs(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};





