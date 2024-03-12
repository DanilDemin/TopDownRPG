#pragma once

enum TAGTYPES
{
	DEFAULT_TAG = 0,
	NEGATIVE_TAG,
	POSITIVE_TAG,
	EXPERIENCE_TAG,
	ENVIRONMETAL_TAG
};

class TextTagSystem
{
private:
	class TextTag
	{
	private:
		sf::Text text;
		float dirX;
		float dirY;
		float lifetime;
		float speed;

	public:
		TextTag(sf::Font& font, std::string text,
			float pos_x, float pos_y,
			float dir_x, float dir_y,
			sf::Color color,
			unsigned char_size,
			float lifetime, float speed)
			: dirX(dir_x)
			, dirY(dir_y)
			, lifetime(lifetime)
			, speed(speed)
		{
			this->text.setFont(font);
			this->text.setPosition(pos_x, pos_y);
			this->text.setFillColor(color);
			this->text.setCharacterSize(char_size);
			this->text.setString(text);
		}

		TextTag(TextTag* tag, float pos_x, float pos_y, std::string str)
			: text(tag->text)
			, dirX(tag->dirX)
			, dirY(tag->dirY)
			, lifetime(tag->lifetime)
			, speed(tag->speed)
		{
			this->text.setPosition(pos_x, pos_y);
			this->text.setString(str);
		}
		


		~TextTag()
		{

		}

		//Accessors
		inline const bool isExpired() const	{return this->lifetime <= 0.f;}



		//Functions
		void update(const float& dt)
		{
			if (this->lifetime >= 0.f)
			{
				//Move the lifetime
				this->lifetime -= 100.f * dt;
				
				//Move the tag
				this->text.move(this->dirX * this->speed * dt, this->dirY * this->speed * dt);
			}
			
		}
		void render(sf::RenderTarget* target)
		{
			target->draw(this->text);
		}
			
	};
		
	sf::Font font;
	std::map<unsigned, TextTag*> tagTemplates;
	std::vector<TextTag*> tags;

	//Private Functions
	void initVariables();
	void initFonts(std::string font_file);
	void initTagtemplates();

public:
	//Con /Des
	TextTagSystem(std::string font_file);
	virtual ~TextTagSystem();

	//Accessors

	//Functions
	void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const std::string str, const std::string prefix = "", const std::string postfix = "");
	void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const int i, const std::string prefix = "", const std::string postfix = "");
	void addTextTag(const unsigned tag_type, const float pos_x, const float pos_y, const float f, const std::string prefix = "", const std::string postfix = "");


	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

