#include "stdafx.h"
#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariables()
{

}


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Aller_BdIt.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{

	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string  key2 = "";


		while (ifs >> key >> key2)
		{
			keybinds[key] = supportedKeys->at(key2);
		}

	}

	ifs.close();
}

void MainMenuState::initGui()
{

	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "ERROR::MAINMENUSTATE::FAILD_TO_DOWNLOAD_BACKGEOUNG_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);



	this->buttons["GAME_STATE"] = new gui::Button(
		gui::p2pX(5.2f, vm), gui::p2pY(9.2f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &font,
		"New Game", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(70, 70, 70, 0), 
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

	this->buttons["SETTINGS_STATE"] = new gui::Button(
		gui::p2pX(5.2f, vm), gui::p2pY(27.8f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &font,
		"Settings", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

	this->buttons["EDITOR_STATE"] = new		gui::Button(
		gui::p2pX(5.2f, vm), gui::p2pY(46.3f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &font,
		"Edditor", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));


	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(5.2f, vm), gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), &font,
		"Quit", gui::calcCharSize(vm),
		sf::Color(70, 70, 70, 200),
		sf::Color(250, 250, 250, 250),
		sf::Color(20, 20, 20, 50),

		sf::Color(100, 100, 100, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0));

}

void MainMenuState::resetGui()
{

	auto it = buttons.begin();
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}

	this->buttons.clear();
	this->initGui();
}

MainMenuState::MainMenuState(StateData* state_data)
	: State(state_data)
{	
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui(); 
	this->resetGui();
}

MainMenuState::~MainMenuState()
{
	auto it = buttons.begin();
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

//Functions
void MainMenuState::updateInput(const float& dt)
{
	
}

void MainMenuState::updateButtons()
{	
	//updates all the buttons in the state and	handles their funcionality
	for (auto& it : buttons)
	{
		it.second->update(this->mousPosWindow);
	}


	//Settings

	//Editor
	if (buttons["GAME_STATE"]->isPressed())
	{
		states->push(new GameState(this->stateData));
	}


	//Settings
	if (buttons["SETTINGS_STATE"]->isPressed())
	{
		states->push(new SettingsState(this->stateData));
	}


	//New Game
	if (buttons["EDITOR_STATE"]->isPressed())
	{
		states->push(new EditorState(this->stateData));
	}

	//Quit the game
	if (buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}

}

void MainMenuState::update(const float& dt)
{	
	updateMousePosition();
	updateInput(dt);
	updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
	{
		target = window;
	}
	
	target->draw(background);

	renderButtons(*target);


	//Remove later!!!!
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << mousePosView.y << " \n";
	mouseText.setString(ss.str());


	target->draw(mouseText);*/
	
}

