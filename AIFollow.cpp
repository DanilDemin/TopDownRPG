#include "stdafx.h"
#include "AIFollow.h"

AIFollow::AIFollow(Entity& self, Entity& entity)
	: AIOption(self, entity)
{
}

AIFollow::~AIFollow()
{
}

void AIFollow::update(const float& dt)
{
	sf::Vector2f moveVect;
	moveVect.x = entity.getPosition().x - self.getPosition().x;
	moveVect.y = entity.getPosition().y - self.getPosition().y;

	float vecLength = sqrt(pow(moveVect.x, 2) + pow(moveVect.y, 2));

	moveVect /= vecLength;

	if ((self.getPosition().x != entity.getPosition().x) && std::abs(vecLength) < 500.f)
	{
		self.move(moveVect.x, moveVect.y, dt);
	}
}
