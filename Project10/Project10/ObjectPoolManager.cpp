#include "ObjectPoolManager.h"
#include"DoubleBuffer.h"

ObjectPoolManager* ObjectPoolManager::instance = nullptr;

void ObjectPoolManager::Initialize()
{
	player = new Player;
	player->Initialize();

	enemy = new Enemy;
	enemy->Initialize();

	for (int i = 0; i < 5; i++)
	{
		bullet[i] = new Bullet;
		bullet[i]->Initialize();
	}

}

void ObjectPoolManager::Progress()
{
	player->Progress();
	enemy->Progress();
	for (int i = 0; i < 5; i++)
	{
		bullet[i]->Progress();
	}
}

void ObjectPoolManager::Render()
{
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			if (map[y][x] == 1)
			{
				DoubleBuffer::Instance()->WriteBuffer(x, y, "бс", 13);
			}
		}
	}
	player->Render();
	enemy->Render();
	
	for (int i = 0; i < 5; i++)
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
	for (int i = 0; i < 5; i++)
	{
		bullet[i]->Release();
		delete bullet[i];
		bullet[i] = nullptr;	
	}

}
