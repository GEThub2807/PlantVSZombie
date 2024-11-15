#pragma once

#include "Entity.h"

class Ball : public Entity
{
public:
	Ball(float radius, const sf::Color& color);

protected:
	void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;
};

