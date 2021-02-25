#include "Stage.h"
#include "CollisionManager.h"


void Stage::Initialize()
{
	player =  ObjectFactory::Instance()->CreateObject(PLAYER);
	enemy = ObjectFactory::Instance()->CreateObject(ENEMY);

}

void Stage::Progress()
{

	if (CollisionManager::Instance()->CollisionCheck(player, enemy))
	{
		enemy->act = false;
	}
	player->Progress();
	enemy->Progress();
}

void Stage::Render()
{
	player->Render();
	enemy->Render();
}

void Stage::Release()
{
	player->Release();
	delete player;
	player = nullptr;

	enemy->Release();
	delete enemy;
	enemy = nullptr;
}
