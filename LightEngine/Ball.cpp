#include "Ball.h"

#include "GameScene.h"

Ball::Ball(float radius, const sf::Color& color) : Entity(radius, color)
{
	SetTag(GameScene::Tag::PROJECTILE);

	SetDirection(1.0f, 0.0f, 100.0f);
}

void Ball::OnUpdate()
{
	sf::Vector2f position = GetPosition(0.f, 0.f);

	int width = GetScene()->GetWindowWidth();

	if (position.x > width)
		Destroy();
}

void Ball::OnCollision(Entity* pCollidedWith)
{
	if (pCollidedWith->IsTag(GameScene::Tag::ZOMBIE))
	{
		Destroy();
	}
}