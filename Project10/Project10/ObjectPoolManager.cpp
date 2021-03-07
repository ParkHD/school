#include "ObjectPoolManager.h"
#include"DoubleBuffer.h"

ObjectPoolManager* ObjectPoolManager::instance = nullptr;

void ObjectPoolManager::Initialize()
{
	player = new Player;
	player->Initialize();

	enemy = new Enemy;
	enemy->Initialize();
}

void ObjectPoolManager::Progress()
{
	player->Progress();
	enemy->Progress();
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

}

void ObjectPoolManager::Release()
{
	player->Release();
	delete player;
	player = nullptr;

	enemy->Release();
	delete enemy;
	enemy = nullptr;
}
