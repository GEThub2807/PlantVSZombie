//#pragma once
//
//#include "Action.h"
//#include "Player.h"
//
//class PlayerAction_Idle : public Action<Player>
//{
//public:
//	void Start(Player* pPlayer) override {}
//	void Update(Player* pPlayer) override {}
//	void End(Player* pPlayer) override {}
//};
//
//class PlayerAction_Passing : public Action<Player>
//{
//	float mShootTimer = 0.0f;
//
//public:
//	void Start(Player* pPlayer) override;
//	void Update(Player* pPlayer) override;
//	void End(Player* pPlayer) override;
//};
//
//class PlayerAction_Running : public Action<Plant>
//{
//	float mReloadTimer = 0.0f;
//
//public:
//	void Start(Plant* pPlant) override;
//	void Update(Plant* pPlant) override;
//	void End(Plant* pPlant) override {};
//
//	friend Plant;
//};