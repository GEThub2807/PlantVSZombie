#include "PlantAction.h"
#include "Plant.h"

#include "GameManager.h"
#include "Ball.h"
#include "GameScene.h"

void PlantAction_Shooting::Start(Plant* pPlant)
{
	mShootTimer = pPlant->mShootCadence;
}

void PlantAction_Shooting::Update(Plant* pPlant)
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pPlant->mShootCadence)
		return;

	mShootTimer -= pPlant->mShootCadence;

	GameScene* pScene = pPlant->GetScene<GameScene>();

	const sf::Vector2f& position = pPlant->GetPosition();

	Ball* pBall = pScene->CreateEntity<Ball>(5.0f, sf::Color::Red);
	pBall->SetPosition(position.x, position.y);

}

void PlantAction_Reloading::Start(Plant* pPlant)
{
	mReloadTimer = 0.f;
}

void PlantAction_Reloading::Update(Plant* pPlant)
{
	mReloadTimer += GameManager::Get()->GetDeltaTime();


	if (mReloadTimer < pPlant->mReloadDuration)
		return;

	pPlant->mAmmo = pPlant->mMaxAmmo;
}