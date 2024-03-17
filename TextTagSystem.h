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
		float acceleration;
		sf::Vector2f velocity;
		int fadeValue;
		bool reverse;


	public:
		TextTag(sf::Font& font, std::string text,
			float pos_x, float pos_y,
			float dir_x, float dir_y,
			sf::Color color,
			unsigned char_size,
			float lifetime,bool reverse, float speed, float acceleration, int fade_value)
			: dirX(dir_x)
			, dirY(dir_y)
			, lifetime(lifetime)
			, reverse(reverse)
			, speed(speed)
			, acceleration(acceleration)
			, fadeValue(fade_value)
		{
			this->text.setFont(font);
			this->text.setPosition(pos_x, pos_y);
			this->text.setFillColor(color);
			this->text.setCharacterSize(char_size);
			this->text.setString(text);

			if (this->reverse)
			{
				this->velocity.x = this->dirX * this->speed;
				this->velocity.y = this->dirY * this->speed;
			}

		}

		TextTag(TextTag* tag, float pos_x, float pos_y, std::string str)
			: text(tag->text)
			, dirX(tag->dirX)
			, dirY(tag->dirY)
			, lifetime(tag->lifetime)
			, reverse(tag->reverse)
			, speed(tag->speed)
			, acceleration(tag->acceleration)
			, velocity(tag->velocity)
			, fadeValue(tag->fadeValue)

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
				
				if (this->acceleration > 0.f)
				{
					if (this->reverse)
					{
						this->velocity.x -= this->dirX * this->acceleration * dt;
						this->velocity.y -= this->dirY * this->acceleration * dt;

						if (abs(this->velocity.x) < 0.f)
						{
							this->velocity.x = 0.f;
						}
						if (abs(this->velocity.y) < 0.f)
						{
							this->velocity.y = 0.f;
						}
						this->text.move(this->velocity * dt);
					}
					else
					{
						this->velocity.x += this->dirX * this->acceleration * dt;
						this->velocity.y += this->dirY * this->acceleration * dt;

						if (abs(this->velocity.x) > this->speed)
						{
							this->velocity.x = this->dirX * this->speed;
						}
						if (abs(this->velocity.y) > this->speed)
						{
							this->velocity.y = this->dirY * this->speed;
						}
						this->text.move(this->velocity * dt);
					}
				}
				else
				{
					//Move the tag
					this->text.move(this->dirX * this->speed * dt, this->dirY * this->speed * dt);
				}
				

				if (this->fadeValue > 0 && this->text.getFillColor().a > this->fadeValue)
				{
					this->text.setFillColor
					(
						sf::Color
						(
							this->text.getFillColor().r,
							this->text.getFillColor().g,
							this->text.getFillColor().b,
							this->text.getFillColor().a - this->fadeValue
						)
					);
				}
				
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

