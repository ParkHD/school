#include "Player.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Player::Initialize()
{
	info.x = 10;
	info.y = 10;
	info.color = ¹àÀº³ë¶õ»ö;
	info.shape = "¿Ê";
}

void Player::Progress()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		info.x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		info.x++;
	}
	//if (GetAsyncKeyState(VK_UP))
	//{
	//	info.y--;
	//}
	if (GetAsyncKeyState(VK_DOWN))
	{
		info.y++;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		info.y += 10;
		Sleep(50);
		info.y -= 10;
	}

	//if (GetAsyncKeyState(VK_SPACE))
	//{
	//	for (int i = 0; i < BulletCount; i++)
	//	{
	//		if (!(ObjectPoolManager::Instance()->bullet[i]->info.act))
	//		{
	//			ObjectPoolManager::Instance()->bullet[i]->info.x = info.x;
	//			ObjectPoolManager::Instance()->bullet[i]->info.y = info.y;
	//			ObjectPoolManager::Instance()->bullet[i]->info.act = true;
	//			break;
	//		}

	//	}

	//}

	if (CollisionManager::Instance()->CollisionCheck(this, ObjectPoolManager::Instance()->enemy))
	{
		ObjectPoolManager::Instance()->enemy->info.act = false;
	}
}

void Player::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(info.x, info.y, info.shape, info.color);
}

void Player::Release()
{
}
