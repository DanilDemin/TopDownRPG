#pragma once

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "Sword.h"
#include "Bow.h"
#include "Enemy.h"
#include "EnemySystem.h" 
#include "TextTagSystem.h"


#include "KnightCreator.h"
#include "ThiefCreator.h"
#include "WizzardCreator.h"


class GameState 
	: public State
{
private:
	sf::View view;
	sf::Vector2i viewGridPosition;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;


	sf::Font font;
	PauseMenu* pmenu;

	sf::Clock keyTimer;
	float keyTimeMax;

	CharacterCreator* creator;
	Player* player;
	PlayerGUI* playerGUI;


	sf::Texture texture;


	std::vector<Enemy*> activeEnemies;
	EnemySystem* enemySystem;
	
	TileMap* tileMap;

	//System
	TextTagSystem* tts;



	//Initializer Functions
	void initDeferredRender();
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initKeyTime();
	void initPlayers();
	void initPlayerGUI();
	void initEnemySystem();
	void initTileMap();
	void initSystems();
	
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	//Accessors
	const bool& getKeyTime();


	//Functions
	void updateView(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePlayerGUI(const float& dt);
	void updatePauseMenuButtons();
	void updateTileMap(const float& dt);
	void updatePlayer(const float& dt);
	void updateComabatAndEnemies(const float& dt);
	void updateCombat(Enemy* enemy, const int index, const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);

};

