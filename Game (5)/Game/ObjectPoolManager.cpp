#include "ObjectPoolManager.h"

ObjectPoolManager* ObjectPoolManager::instance = nullptr;

void ObjectPoolManager::Initialize()
{
	player = ObjectFactory::Instance()->CreateObject(PLAYER);
	enemy = ObjectFactory::Instance()->CreateObject(ENEMY);
	for (int i = 0; i < BulletCount; i++)
	{
		bullet[i] = ObjectFactory::Instance()->CreateObject(BULLET);
	}
	
}

void ObjectPoolManager::Progress()
{
	player->Progress();
	enemy->Progress();
	for (int i = 0; i < BulletCount; i++)
	{
		bullet[i]->Progress();
	}
}

void ObjectPoolManager::Render()
{
	player->Render();
	enemy->Render();
	for (int i = 0; i < BulletCount; i++)
	{
		bullet[i]->Render();
	}
}

void ObjectPoolManager::Release()
{
	player->Release();
	delete player;
	player = nullptr;

	enemy->Release();
	delete enemy;
	enemy = nullptr;

	for (int i = 0; i < BulletCount; i++)
	{
		bullet[i]->Release();
		delete bullet[i];
		bullet[i] = nullptr;
	}
}

void ObjectPoolManager::Release(Obj* bullet)
{
	delete bullet;
	bullet = nullptr;
}
