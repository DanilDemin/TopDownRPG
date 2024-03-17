#pragma once

#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "HitboxComponent.h"
#include "AttributeComponent.h"
#include "SkillComponent.h"


class MovementComponent;
class AnimationComponent;
class HitboxComponent;
class AttributeComponent;
class SkillComponent;

class Entity
{
private:
	void initVariables();
protected:
	
	sf::Sprite sprite;
	
	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	AttributeComponent* attributeComponent;
	SkillComponent* skillComponent;


public:
	//Con/Des
	Entity();
	virtual ~Entity();

	//Component Functions
	void setTexture(sf::Texture& texture);
	void createHitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	void createMovementComponent(const float maxVelocity,
		const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);
	void createAttributeComponent(const unsigned level);
	void createSkillComponent();
	void createAIComponent();


	//Accessors
	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::Vector2i& getGridPosition(const int gridSizeU) const;
	virtual const sf::FloatRect getGlobalBounds() const;
	virtual const sf::FloatRect getNextPositionBounds(const float& dt) const;
	virtual const sf::Vector2f& getCenter() const;


	virtual const float& getWidth() const;
	virtual const float& getHeight() const;



	virtual void setPosition(const float x, const float y);

	//Functions
	virtual void move(const float dir_x, const float dir_y, const float& dt);
	virtual void stopVelocity();
	virtual void stopVelocityX();
	virtual void stopVelocitY();


	//Calculations
	virtual const float getDistance(const Entity& entity) const;
	

	virtual void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view) = 0;
	virtual void render(sf::RenderTarget& target, const bool show_hitbox = false) = 0;
};

