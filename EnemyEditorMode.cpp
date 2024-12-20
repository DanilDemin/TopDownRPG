#include "stdafx.h"
#include "EnemyEditorMode.h"


//Initializer functions	
void EnemyEditorMode::initVariables()
{
	this->type = 0;
	this->amount = 0;
	this->timeToSpawn = 60;
	this->maxDistance = 1000.f;
}


void EnemyEditorMode::initGui()
{
	//Text
	this->cursorText.setFont(*this->editorStateData->font);
	this->cursorText.setCharacterSize(12);
	this->cursorText.setFillColor(sf::Color::White);
	this->cursorText.setPosition(this->editorStateData->mousePosView->x, this->editorStateData->mousePosView->y - 50);


	//General Gui
	this->sidebar.setSize(sf::Vector2f(80.f, static_cast<float>(this->stateData->gfxSettings->resolution.height)));
	this->sidebar.setFillColor(sf::Color(50, 50, 50, 100));
	this->sidebar.setOutlineColor(sf::Color(200, 200, 200, 150));
	this->sidebar.setOutlineThickness(1.f);


	this->selectorRect.setSize(sf::Vector2f(this->stateData->gridSize,
		this->stateData->gridSize));
	this->selectorRect.setFillColor(sf::Color(255, 255, 255, 150));
	this->selectorRect.setOutlineThickness(1.f);
	this->selectorRect.setOutlineColor(sf::Color::Green);
}

EnemyEditorMode::EnemyEditorMode(StateData* state_data, TileMap* tile_map, EditorStateData* editor_state_data)
	: EditorMode(state_data, tile_map, editor_state_data)
{
	this->initVariables();
	this->initGui();
}

EnemyEditorMode::~EnemyEditorMode()
{

}

//Update
void EnemyEditorMode::updateInput(const float& dt)
{
	//Add a tile to the tileMap
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
	{
		if (!this->sidebar.getGlobalBounds().contains(sf::Vector2f(*this->editorStateData->mousPosWindow)))
		{
		this->tileMap->addTile(this->editorStateData->mousePosGrid->x, this->editorStateData->mousePosGrid->y, 0, this->textureRect,
			this->type, this->amount, this->timeToSpawn, this->maxDistance);
		}
	}
	//Remove a tile from the tilemap
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->getKeytime())
	{
		if (!this->sidebar.getGlobalBounds().contains(sf::Vector2f(*this->editorStateData->mousPosWindow)))
		{ 
			/*if (this->tileMap->checkType(this->editorStateData->mousePosGrid->x, this->editorStateData->mousePosGrid->y, 0, Tiletypes::ENEMYSPAWNER))*/
			 
			this->tileMap->removeTile(this->editorStateData->mousePosGrid->x, this->editorStateData->mousePosGrid->y, 0, Tiletypes::ENEMYSPAWNER);
			 
			
		}
	}


	//Toggle collision
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->editorStateData->keybinds->at("TYPE_UP"))) && this->getKeytime())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			if (this->type > 0) { this->type--; }
		}
		else if (this->type < 1000) { this->type++; }
		else { this->type = 0; }
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->editorStateData->keybinds->at("AMOUNT_UP"))) && this->getKeytime())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			if (this->amount > 0) { this->amount--; }
		}
		else if (this->amount < 1000) { this->amount++; }
		else { this->amount = 0; }
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->editorStateData->keybinds->at("TTS_UP"))) && this->getKeytime())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			if (this->timeToSpawn > 0) { this->timeToSpawn--; }
		}
		else if (this->timeToSpawn < 1000) { this->timeToSpawn++; }
		else { this->timeToSpawn = 0; }
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->editorStateData->keybinds->at("MD_UP"))) && this->getKeytime())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			if (this->maxDistance > 0) { this->maxDistance--; }
		}
		else if (this->maxDistance < 1000) { this->maxDistance++; }
		else { this->maxDistance = 0; }
	}




	////Set lock on / off
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->editorStateData->keybinds->at("TOGGLE_TILE_LOCK"))) && this->getKeytime())
	//{
	//	if (this->tileAddLock)
	//	{
	//		this->tileAddLock = false;
	//	}
	//	else
	//	{
	//		this->tileAddLock = true;
	//	}
	//}

}

void EnemyEditorMode::updateGui(const float& dt)
{
	this->selectorRect.setPosition(
		this->editorStateData->mousePosGrid->x * this->stateData->gridSize,
		this->editorStateData->mousePosGrid->y * this->stateData->gridSize
	);

	this->cursorText.setPosition(
		this->editorStateData->mousePosView->x + 100,
		this->editorStateData->mousePosView->y - 50
	);

	std::stringstream ss;
	ss <<
		"\n" << "Type type: " << this->type <<
		"\n" << "Enemy amount: " << this->amount <<
		"\n" << "Time to spawn: " << this->timeToSpawn <<
		"\n" << "Max distance: " << this->maxDistance;


	this->cursorText.setString(ss.str());

}

void EnemyEditorMode::update(const float& dt)
{
	this->updateInput(dt);
	this->updateGui(dt);
}


//Render
void EnemyEditorMode::renderGui(sf::RenderTarget& target)
{
	target.setView(*this->editorStateData->view);
	target.draw(this->selectorRect);
	target.draw(this->cursorText);

	target.setView(target.getDefaultView());
	target.draw(this->sidebar);
}

void EnemyEditorMode::render(sf::RenderTarget& target)
{
	this->renderGui(target);
}
