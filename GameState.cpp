#include "stdafx.h"
#include "GameState.h"



//Initializer Functions

void GameState::initDeferredRender()
{
	this->renderTexture.create(
		this->stateData->gfxSettings->resolution.width,
		this->stateData->gfxSettings->resolution.height
	);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0,
			0,
			this->stateData->gfxSettings->resolution.width,
			this->stateData->gfxSettings->resolution.height
		)
	);

}

void GameState::initView()
{
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);



	this->view.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f)
	);

}

void GameState::initKeybinds()
{	

	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string  key2 = "";


		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}

	}

	ifs.close();	 
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Aller_BdIt.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}


void GameState::initTextures()
{	 
	if (!this->textures["Player_Spritelist"].loadFromFile(
		"Resources/Images/Sprites/Player/Knight/KhightSheet.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}


	if (!this->textures["Skeleton_Spritelist"].loadFromFile(
		"Resources/Images/Sprites/Enemy/SkeletonSheet.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_ENEMY_TEXTURE";
	}

}

void GameState::initPauseMenu()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);
	this->pmenu->addButton("QUIT", gui::p2pY(83.3f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
}

void GameState::initKeyTime()
{
	this->keyTimeMax = 0.3f;
	this->keyTimer.restart();
}

void GameState::initPlayers()
{
	this->player = new Player(200, 200, this->textures["Player_Spritelist"]);
}

void GameState::initPlayerGUI()
{
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution);
}

void GameState::initEnemySystem()
{
	this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
	 
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap("text.txt");
}

void GameState::initSystems()
{
	this->tts = new TextTagSystem("Fonts/Aller_BdIt.ttf");
}

//Con/Des
GameState::GameState(StateData* state_data)
	: State(state_data)
{
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initKeyTime();
	this->initPlayers();
	this->initPlayerGUI();
	this->initEnemySystem();
	this->initTileMap();
	this->initSystems();
}

GameState::~GameState()
{
	delete this->pmenu;
	delete this->player;
	delete this->playerGUI;
	delete this->tileMap;
	delete this->enemySystem;
	delete this->tts;
	 
	for (size_t i = 0; i < this->activeEnemies.size(); i++)
	{
		delete this->activeEnemies[i];
	}
}

const bool& GameState::getKeyTime()
{
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}
	return false;
}


//Functions
void GameState::updateView(const float& dt)
{
	

	//I will change + 700.f : I have to change texture scale problem
	 
	this->view.setCenter(
		std::floor(this->player->getPosition().x + (static_cast<float>(this->mousPosWindow.x)
			- static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
		std::floor(this->player->getPosition().y + (static_cast<float>(this->mousPosWindow.y)
			- static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
	);
	 



	//Update position of the camera left right top bottom
	
	//Ox : right and left 
	if (this->tileMap->getMaxSizeWorldF().x >= this->view.getSize().x ) 
	{
		if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f)
		{
			this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
		else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeWorldF().x)
		{
			this->view.setCenter(this->tileMap->getMaxSizeWorldF().x - this->view.getSize().x, this->view.getCenter().y);
		}
	}
	
	//Oy : top and bottom
	if (this->tileMap->getMaxSizeWorldF().y >= this->view.getSize().y)
	{
		if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f)
		{
			this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
		}
		else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeWorldF().y)
		{
			this->view.setCenter(this->view.getCenter().x, this->tileMap->getMaxSizeWorldF().y - this->view.getSize().y / 2.f);
		}
	}
	

	this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize);
	this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);

}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->paused)
		{
			this->pauseState();
		}
		else
		{
			this->unpauseState();
		}
	}
}

void GameState::updatePlayerInput(const float& dt)
{
	 
	 
	 
		//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
	{
		this->player->move(-1.f, 0.f, dt);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
	{
		this->player->move(1.f, 0.f, dt);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
	{
		this->player->move(0.f, -1.f, dt);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
	{
		this->player->move(0.f, 1.f, dt);
		/*if (this->getKeytime())
			this->player->loseEXP(20);*/
	}
	 
}

void GameState::updatePlayerGUI(const float& dt)
{
	this->playerGUI->update(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("TOGGLE_PLAYER_TAB_CHARACTER"))) && this->getKeyTime())
	{
		this->playerGUI->toggleCharacterTab();
	}
}

void GameState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
	{
		this->endState();
	}
}

void GameState::updateTileMap(const float& dt)
{
	this->tileMap->updateWorldBoundsCollision(this->player, dt);
	this->tileMap->updateTileCollision(this->player, dt);
	this->tileMap->updateTiles(this->player, dt, *this->enemySystem);
}

void GameState::updatePlayer(const float& dt)
{
	this->player->update(dt, this->mousePosView, this->view);
}

void GameState::updateComabatAndEnemies(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->getWeapon()->getAttackTimer())
	{
		this->player->setInitAtack(true);
	}


	unsigned index = 0;

	//enemies
	for (auto* enemy : this->activeEnemies)
	{
		enemy->update(dt, this->mousePosView, this->view);

		this->tileMap->updateWorldBoundsCollision(enemy, dt);
		this->tileMap->updateTileCollision(enemy, dt);
		
		this->updateCombat(enemy, index, dt);	


		//Dangerous!!!
		if (enemy->isDead())
		{
			this->player->gainEXP(enemy->getGainExp());
			this->tts->addTextTag(TAGTYPES::EXPERIENCE_TAG, this->player->getCenter().x - 50.f, this->player->getCenter().y - 30.f, static_cast<int>(enemy->getGainExp()), "+", "EXP");

			this->enemySystem->removeEnemy(index);
			continue;
		}
		//Problem is about enemy remove (out of view of player)
		/*else if (enemy->getRespawnTimerDone())
		{
			this->enemySystem->removeEnemy(index);
			continue;
		}*/

		++index;
	}

	this->player->setInitAtack(false);

}

void GameState::updateCombat(Enemy* enemy, const int index, const float& dt)
{
	if ( this->player->getInitAtack()
		&& enemy->getGlobalBounds().contains(this->mousePosView)
		&& enemy->getDistance(*this->player) < this->player->getWeapon()->getRange()
		&& enemy->getDamageTimeDone()
		)
	{
		//Get to this
		int dmg = static_cast<int>(this->player->getDamage());

		enemy->loseHp(dmg);
		enemy->resetDamageTimer();

		this->tts->addTextTag(TAGTYPES::DEFAULT_TAG, enemy->getPosition().x + 50.f, enemy->getPosition().y, dmg, "", "");
	}

	//Check for enemy damage

	if (enemy->getGlobalBounds().intersects(this->player->getGlobalBounds()) && this->player->getDamageTimer())
	{
		int dmg = enemy->getAttributeComp()->damageMax;
		this->player->loseHp(dmg);
		this->tts->addTextTag(TAGTYPES::NEGATIVE_TAG, this->player->getCenter().x - 50.f, this->player->getCenter().y, dmg, "-", "HP");
	}

}


void GameState::update(const float& dt)
{	
	this->updateMousePosition(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);
	

	if (!this->paused) //Unpaused update
	{
		

		this->updateView(dt);
		this->updatePlayerInput(dt);
		this->updateTileMap(dt);
		this->updatePlayer(dt);
		this->updatePlayerGUI(dt);

		//Update all enemies
		this->updateComabatAndEnemies(dt);

		//Update systems
		this->tts->update(dt);


	}
	else //Paused update
	{	
		
		this->pmenu->update(this->mousPosWindow);
		this->updatePauseMenuButtons();
	}
	


		 
}

void GameState::render(sf::RenderTarget* target)
{
	
	if (!target)
	{
		target = this->window;
	}
	
	this->renderTexture.clear();

	this->renderTexture.setView(this->view);


	this->tileMap->render(
		this->renderTexture,
		this->player->getGridPosition(static_cast<int>(this->stateData->gridSize)),
		false
	);


	//enemies
	for (auto* enemy : this->activeEnemies)
	{
		enemy->render(this->renderTexture, true);
	}



	this->player->render(this->renderTexture, true);
	
	


	this->tileMap->renderDeferred(this->renderTexture);

	this->tts->render(this->renderTexture);


	//Render GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);


	if (this->paused)//Paused menu render
	{
		/*this->renderTexture.setView(this->renderTexture.getDefaultView());*/
		this->pmenu->render(this->renderTexture);
	}

	//FINAL RENDER

	this->renderTexture.display();
	this->renderSprite.setTexture(this->renderTexture.getTexture());
	target->draw(this->renderSprite);


	
}
