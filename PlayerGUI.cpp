#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	this->font.loadFromFile("Fonts/Aller_BdIt.ttf");
}

void PlayerGUI::initLevelBar()
{
	float width = gui::p2pX(2.f, vm);
	float height = gui::p2pY(3.7f, vm);
	float x = gui::p2pX(2.f, vm);
	float y = gui::p2pY(3.7f, vm);

	//Back
	this->levelBarBack.setSize(sf::Vector2f(width, height));
	this->levelBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->levelBarBack.setPosition(x, y);

	this->levelBarText.setFont(this->font);
	this->levelBarText.setCharacterSize(gui::calcCharSize(vm, 200));
	this->levelBarText.setPosition(this->levelBarBack.getPosition().x + gui::p2pX(0.5f, vm), this->levelBarBack.getPosition().y + gui::p2pY(0.46f, vm));
}

void PlayerGUI::initHpBar()
{
	this->hpBar = new gui::ProgressBar(
		2.f, 8.3f, 15.6f, 3.7f,
		this->player->getAttributecomponent()->hpMax,
		sf::Color::Red, 200,
		this->vm, &this->font);
}

void PlayerGUI::initEXPBar()
{
	this->expBar = new gui::ProgressBar(
		2.f, 13.f, 10.f, 3.7f,
		this->player->getAttributecomponent()->expNext,
		sf::Color::Blue, 200,
		this->vm, &this->font);
}

void PlayerGUI::initPlayerTabs(sf::VideoMode& vm, sf::Font& font, Player& player)
{
	this->playerTabs = new PlayerGUITabs(vm, font, player);
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm)
	: player(player)
	, vm(vm)
{
	this->initFont();
	this->initLevelBar();
	this->initHpBar();
	this->initEXPBar();
	this->initPlayerTabs(vm, this->font, *player);
	
}

PlayerGUI::~PlayerGUI()
{
	delete this->hpBar;
	delete this->expBar;
	delete this->playerTabs;
}

const bool PlayerGUI::getTabsOpen() const
{
	return this->playerTabs->tabsOpen();
}

void PlayerGUI::toggleCharacterTab()
{
	this->playerTabs->toggleTab(PLAYER_TABS::CHARACTER_TAB);
}


//Functions
void PlayerGUI::updateLevelbar()
{
	this->levelBarString = std::to_string(this->player->getAttributecomponent()->level);
	this->levelBarText.setString(this->levelBarString);
}


void PlayerGUI::updateEXPBar()
{
	this->expBar->update(this->player->getAttributecomponent()->exp);
}


void PlayerGUI::updateHpBar()
{
	this->hpBar->update(this->player->getAttributecomponent()->hp);
}

void PlayerGUI::updatePlayerTabs()
{
	this->playerTabs->update();
}


void PlayerGUI::update(const float& dt)
{
	this->updateLevelbar();
	this->updateHpBar();
	this->updateEXPBar();
	this->updatePlayerTabs();
}

void PlayerGUI::renderLevelBar(sf::RenderTarget& target)
{
	target.draw(this->levelBarBack);
	target.draw(this->levelBarText);
}

void PlayerGUI::renderEXPBAR(sf::RenderTarget& target)
{
	this->expBar->render(target);
}

void PlayerGUI::renderHpBar(sf::RenderTarget& target)
{
	this->hpBar->render(target);
}

void PlayerGUI::renderPlayerTabs(sf::RenderTarget& target)
{
	this->playerTabs->render(target);
}


void PlayerGUI::render(sf::RenderTarget& target)
{
	this->renderLevelBar(target);
	this->renderHpBar(target);
	this->renderEXPBAR(target);
	this->renderPlayerTabs(target);

}



