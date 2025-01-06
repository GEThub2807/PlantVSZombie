#pragma once

#include "GameManager.h"

#include <list>

class Plant;
class Zombie;

namespace sf 
{
	class Event;
}

struct AABB 
{
	int xMin;
	int yMin;
	int xMax;
	int yMax;
};

class GameScene : public Scene
{
public:
	enum Tag
	{
		PLANT,
		ZOMBIE,
		PROJECTILE,
	};

	int mLaneZombieCount[5] = {0, 0, 0, 0, 0};		
	AABB mAreas[5];

	Plant* pPlant;
	Zombie* pZombie;


private:
	int GetClickedArea(int x, int y) const;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	bool IsZombieInArea(int index) const;
	void OnDestroyZombie(int lane);
};

