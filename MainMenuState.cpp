#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariables()
{
	this->background.setSize(
		sf::Vector2f
		(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
		)
	);
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "ERROR::MAINMENUSTATE::FAILD_TO_DOWNLOAD_BACKGEOUNG_TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);


}

void MainMenuState::initBackground()
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

void MainMenuState::initButtons()
{
	buttons["GAME_STATE"] = new Button(100, 100, 250, 100, &font,
		"New Game", sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 250),
		sf::Color(20, 20, 20, 200));

	buttons["SETTINGS"] = new Button(100, 300, 250, 100, &font,
		"Settings", sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 250),
		sf::Color(20, 20, 20, 200));

	buttons["EXIT_STATE"] = new Button(100, 500, 250, 100, &font,
		"Quit", sf::Color(100, 100, 100, 200),
		sf::Color(150, 150, 150, 250),
		sf::Color(20, 20, 20, 200));

}

MainMenuState::MainMenuState(sf::RenderWindow* window,
	std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{	
	initVariables();
	initBackground();
	initFonts();
	initKeybinds();
	initButtons(); 
}

MainMenuState::~MainMenuState()
{
	auto it = buttons.begin();
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}


void MainMenuState::updateInput(const float& dt)
{
	
}

void MainMenuState::updateButtons()
{	
	//updates all the buttons in the state and	handles their funcionality
	for (auto& it : buttons)
	{
		it.second->update(mousePosView);
	}


	//New Game
	if (buttons["GAME_STATE"]->isPressed())
	{
		states->push(new GameState(window, supportedKeys, states));
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

void MainMenuState::renderButtons(sf::RenderTarget* target)
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

	renderButtons(target);


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

