#pragma once
class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	sf::FloatRect nextPosition;
	float offSetX;
	float offSetY;
	float width;
	float height;

public:
	//Con/Des
	HitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	virtual ~HitboxComponent();

	//Accessors
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect& getNextPosition(const sf::Vector2f& velocity);
	const float& getWidth() const;
	const float& getHeight() const;
	
	//Modifiers
	void setPosition(const sf::Vector2f& position);
	void setPosition(const float x, const float y);
	
	//Functions
	bool intersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
};

