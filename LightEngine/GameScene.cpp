#include "GameScene.h"

#include "Player.h"
#include "Debug.h"

void GameScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float playerRadius = 30.0f;
	float playerHeight = playerRadius * 2;
	float spaceBetweenPlayers = 125;

	float totalHeight = (spaceBetweenPlayers * 2) + (playerHeight * 5);
	float spacing = height - totalHeight; //taille de la fenetre - tout ce qu'il y a dans l'axe y de la fenetre 

	float startXBlue = playerRadius * 2;
	float startXRed = width - (playerRadius * 2);

	float startY = playerRadius + (spacing / 2); //L'espace du haut + la taille de la moitié de la balle


	Player* BlueTeam[5];
	Player* RedTeam[5];

	for (int i = 0; i < 5; i++) 
	{
		BlueTeam[i] = CreateEntity<Player>(playerRadius, sf::Color::Green);
		BlueTeam[i]->SetPosition(startXBlue, startY, 0.5f, 0.5f);
		BlueTeam[i]->SetAreaIndex(i); //Définit la lane où se trouve l'objet

		RedTeam[i] = CreateEntity<Player>(playerRadius, sf::Color::Green);
		RedTeam[i]->SetPosition(startXRed, startY, 0.5f, 0.5f);
		RedTeam[i]->SetAreaIndex(i); //Définit la lane où se trouve l'objet

		int xMin = 0; //balle * balle
		int yMin = startY - playerRadius;
		int xMax = width + 1; //Largeur de la fenetre
		int yMax = startY + playerRadius; //balle + balle + startY

		mAreas[i] = { xMin, yMin - static_cast <int>(playerRadius), xMax, yMax + static_cast <int>(playerRadius) }; //Lane

		startY += spaceBetweenPlayers; //espace entre lane
	}
}

void GameScene::OnUpdate()
{
	for (int i = 0; i < 5; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}
}

int GameScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < 5; i++)
	{
		const AABB* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)
			return i;
	}

	return -1;
}

void GameScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if(index == -1)
		return;

	const AABB* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Zombie* pZombie = CreateEntity<Zombie>(25, sf::Color::Red);
	pZombie->SetPosition(event.mouseButton.x, y, 0.5f, 0.5f);
	pZombie->SetLane(index);
	
	mLaneZombieCount[index]++;
}

bool GameScene::IsZombieInArea(int index) const
{
	_ASSERT(index >= 0 && index < 5);

	return mLaneZombieCount[index] > 0;
}

void GameScene::OnDestroyZombie(int lane)
{
	_ASSERT(lane >= 0 && lane < 5);
	if(mLaneZombieCount[lane] <= 0)
		return;

	mLaneZombieCount[lane]--;
}