#include "Player.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	color = ¹àÀº³ë¶õ»ö;
	shape = "¿Ê";
}

void Player::Progress()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		count = 0;
		x--;
		if (x < 0)
			x++;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		count = 1;
		x++;
		if (x > 50)
			x--;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		y--;
		if (y < 0)
			y++;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
		if (y > 50)
			y--;
	}

	if (GetAsyncKeyState(VK_SPACE)) // shot
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!(ObjectPoolManager::Instance()->bullet[i]->act))
			{
				ObjectPoolManager::Instance()->bullet[i]->count = count;

				ObjectPoolManager::Instance()->bullet[i]->x = x;
				ObjectPoolManager::Instance()->bullet[i]->y = y;
				ObjectPoolManager::Instance()->bullet[i]->act = true;
				break;
			}
		}
	}

	if (CollisionManager::Instance()->CollisionCheck(this, ObjectPoolManager::Instance()->enemy))
	{
		ObjectPoolManager::Instance()->enemy->act = false;
	}
}

void Player::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
}

void Player::Release()
{
}
