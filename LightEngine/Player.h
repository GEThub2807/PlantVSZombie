#pragma once

#include "Entity.h"
#include "StateMachine.h"

class Player : public Entity
{
	//StateMachine<Player> mStateMachine;

	//enum State
	//{
	//	Idle, //Debug (remplacer par freeze ?)
	//	Passing,
	//	Running,

	//	Count
	//};

	float speed;
	float acceleration = speed * 1.5;
	int mAreaIndex;

public:
	Player(float radius, const sf::Color& color);

	void SetAreaIndex(int index)                 { mAreaIndex = index; }
	int GetAreaIndex()                           { return mAreaIndex; }
	//const char* GetStateName(State state) const;

protected:
	//void OnUpdate() override;
	void OnCollision(Entity* pCollidedWith) override;

	//friend class PlayerAction_Idle;
	//friend class PlayerAction_Running;
	//friend class PlayerAction_Passing;
};
