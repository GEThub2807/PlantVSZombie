#include "Player.h"

#include <string>

#include "GameScene.h"
#include "Ball.h"

//#include "PlayerAction.h"
//#include "PlayerCondition.h"

#include "Debug.h"

Player::Player(float radius, const sf::Color& color) : Entity(radius, color) //, mStateMachine(this, State::Count)
{
//	mAreaIndex = -1;
//	
//	//IDLE / FREEZE
//	{
//		Behaviour<Player>* pIdle = mStateMachine.CreateBehaviour(State::Idle);
//		pIdle->AddAction(new PlayerAction_Idle());
//
//		//-> PASSING
//		{
//			auto transition = pIdle->CreateTransition(State::Passing);
//
//			auto condition = transition->AddCondition<PlayerCondition_ZombieOnLane>();
//		}
//
//		//-> RUNNING
//		{
//			auto transition = pIdle->CreateTransition(State::Running);
//
//			auto condition1 = transition->AddCondition<PlayerCondition_FullAmmo>();
//			condition1->expected = false;
//
//			auto condition2 = transition->AddCondition<PlayerCondition_ZombieOnLane>();
//			condition2->expected = false;
//		}
//	}
//
//	//PASSING
//	{
//		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Passing);
//		pShooting->AddAction(new PlayerAction_Passing());
//
//		//-> IDLE
//		{
//			auto transition = pShooting->CreateTransition(State::Idle);
//
//			auto condition = transition->AddCondition<PlayerCondition_ZombieOnLane>();
//			condition->expected = false;
//		}
//
//		//-> RUNNING (front / back)
//		{
//			auto transition = pShooting->CreateTransition(State::Running);
//
//			transition->AddCondition<PlayerCondition_NoAmmo>();
//		}
//	}
//
//	//Running
//	{
//		Behaviour<Plant>* pShooting = mStateMachine.CreateBehaviour(State::Running);
//		pShooting->AddAction(new PlayerAction_Running());
//
//		//-> IDLE
//		{
//			auto transition = pShooting->CreateTransition(State::Idle);
//
//			auto condition = transition->AddCondition<PlayerCondition_FullAmmo>();
//		}
//	}
//
//	mStateMachine.SetState(State::Idle);
}

//const char* Player::GetStateName(State state) const
//{
//	switch (state)
//	{
//	case Idle: return "Idle";
//	case Passing: return "Passing";
//	case Running: return "Running";
//	default: return "Unknown";
//	}
//}

//void Player::OnUpdate()
//{
//	const sf::Vector2f& position = GetPosition();
//	const char* stateName = GetStateName((Player::State)mStateMachine.GetCurrentState());
//
//	std::string ammo = std::to_string(mAmmo) + "/" + std::to_string(mMaxAmmo);
//
//	Debug::DrawText(position.x, position.y - 50, stateName, 0.5f, 0.5f, sf::Color::Red);
//	Debug::DrawText(position.x, position.y, ammo, 0.5f, 0.5f, sf::Color::Blue);
//
//	mStateMachine.Update();
//}

void Player::OnCollision(Entity* collidedWith)
{
	//if (Player a la balle){donne la balle au PlayerAuContact}
}
