#include "stdafx.h"
#include "TextTagSystem.h"

//Private Functions
void TextTagSystem::initVariables()
{

}

void TextTagSystem::initFonts(std::string font_file)
{
	if (!this->font.loadFromFile(font_file))
	{
		std::cout << "ERROE::TEXTADDSYSTEM::CONSRTUCTOR::FAILD TO LOAD FONT" << font_file << "\n";
	}
}

void TextTagSystem::initTagtemplates()
{
	this->tagTemplates[TAGTYPES::DEFAULT_TAG] = new TextTag(this->font, "HUY", 800.f, 800.f, 0.f, -1.f, sf::Color::White, 60, 100.f, true, 300.f, 500.f, 2);
	this->tagTemplates[TAGTYPES::NEGATIVE_TAG] = new TextTag(this->font, "HUY", 800.f, 800.f, 0.f, 1.f, sf::Color::Red, 60, 100.f, true, 350.f, 500.f, 2);
	this->tagTemplates[TAGTYPES::EXPERIENCE_TAG] = new TextTag(this->font, "HUY", 800.f, 800.f, 0.f, -1.f, sf::Color::Cyan, 60, 150.f, true, 350.f, 500, 2);
}

//Con /Des
TextTagSystem::TextTagSystem(std::string font_file)
{
	

	this->initVariables();
	this->initFonts(font_file);
	this->initTagtemplates();

}

TextTagSystem::~TextTagSystem()
{
	//Clean up tags
	for (auto* tag : this->tags)
	{
		delete tag;
	}
	//Clean up templates
	for (auto& tag : this->tagTemplates)
	{
		delete tag.second;
	}
}

//Accessors


//Functions
void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const std::string str, const std::string prefix, const std::string postfix)
{
	std::stringstream ss;

	ss << prefix << " " << str << " " << postfix;

	this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const int i, const std::string prefix, const std::string postfix)
{
	std::stringstream ss;

	ss << prefix << " " << i << " " << postfix;

	this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void TextTagSystem::addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const float f, const std::string prefix, const std::string postfix)
{
	std::stringstream ss;

	ss << prefix << " " << f << " " << postfix;

	this->tags.push_back(new TextTag(this->tagTemplates[tag_type], pos_x, pos_y, ss.str()));
}

 

void TextTagSystem::update(const float& dt)
{
	for (size_t i = 0; i < this->tags.size(); ++i)
	{
		this->tags[i]->update(dt);

		if (this->tags[i]->isExpired())
		{
			delete this->tags[i];
			this->tags.erase(this->tags.begin() + i);
		}
	}
}

void TextTagSystem::render(sf::RenderTarget& target)
{
	for (auto& tag : this->tags)
	{
		tag->render(&target);
	}
}

 