#include "Enemy.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "Obj.h"

void Enemy::Initialize()
{
	info.act = true;
	info.x = 20;
	info.y = 20;
	info.color = ¹àÀº»¡°£»ö;
	info.shape[0] = "¡á¡á¡á¡á";
	info.shape[1] = "¡á¡á¡á¡á";
	info.shape[2] = "¡á¡á¡á¡á";

	info.dir = GetRandomDirection();

	timeStep = 0;
}

void Enemy::Progress()
{
	timeStep++;
	if (timeStep > 1)
	{
		if (!info.act)
		{
			SetReposition();
		}

		if (info.act)
		{
			for (int i = 0; i < BulletCount; i++)
			{
				Obj* bullet = ObjectPoolManager::Instance()->bullet[i];
				if (bullet->info.act)
				{
					if (CollisionManager::Instance()->CollisionCheck(this->GetRect(), bullet->info.x, bullet->info.y))
					{
						bullet->info.act = false;
						info.act = false;
					}
				}
			}

			CheckCollision();
		}


		timeStep = 0;
	}
	

}

void Enemy::Render()
{
	if (info.act)
	{
		for (int i = 0; i < ObjHeight; i++)
		{
			DoubleBuffer::Instance()->WriteBuffer(info.x, info.y + i, info.shape[i], info.color);
		}

	}

}

void Enemy::Release()
{
}


DIR Enemy::GetRandomDirection()
{
	int randValue = rand() % 5;

	return (DIR)randValue;
}

void Enemy::CheckCollision()
{
	switch (info.dir)
	{
	case LEFT:
		info.x--;
		if (CheckLeftCollision())
		{
			info.x++;
			info.dir = GetRandomDirection();
		}
		break;
	case RIGHT:
		info.x++;
		if (CheckRightCollision())
		{
			info.x--;
			info.dir = GetRandomDirection();
		}
		break;
	case UP:
		info.y--;
		if (CheckTopCollision())
		{
			info.y++;
			info.dir = GetRandomDirection();
		}
		break;
	case DOWN:
		info.y++;
		if (CheckBottomCollision())
		{
			info.y--;
			info.dir = GetRandomDirection();
		}
		break;
	default:
		break;
	}
}

bool Enemy::CheckLeftCollision()
{

	for (int i = 0; i < ObjHeight; i++)
	{
		if (ObjectPoolManager::Instance()->CheckMap(info.x, info.y + i) == 1)
		{
			return true;
		}
	}

	return false;
}

bool Enemy::CheckRightCollision()
{
	for (int i = 0; i < ObjHeight; i++)
	{
		if (ObjectPoolManager::Instance()->CheckMap(info.x + ObjWidth - 1, info.y + i) == 1)
		{
			return true;
		}
	}
	return false;
}

bool Enemy::CheckTopCollision()
{
	for (int i = 0; i < ObjWidth; i++)
	{
		if (ObjectPoolManager::Instance()->CheckMap(info.x + i, info.y) == 1)
		{
			return true;
		}
	}
	return false;
}

bool Enemy::CheckBottomCollision()
{
	for (int i = 0; i < ObjWidth; i++)
	{
		if (ObjectPoolManager::Instance()->CheckMap(info.x + i, info.y + ObjHeight - 1) == 1)
		{
			return true;
		}
	}
	return false;
}

void Enemy::SetReposition()
{
	info.x = rand() % 50;
	info.y = rand() % 50;

	while (true)
	{
		bool check = false;

		for (int y = 0; y < ObjHeight; y++)
		{
			for (int x = 0; x < ObjWidth; x++)
			{
				if (ObjectPoolManager::Instance()->CheckMap(info.x + x, info.y + y))
				{
					check = true;
					break;
				}
			}
		}

		if (check)
		{
			info.y = rand() % 50;
			info.x = rand() % 50;
		}
		else
		{
			break;
		}

	}

	info.act = true;
}


