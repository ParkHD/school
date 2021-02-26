#include "Enemy.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "Obj.h"

void Enemy::Initialize()
{
	act = true;
	x = 20;
	y = 20;
	color = ¹àÀº»¡°£»ö;
	shape = "º¿";
}

void Enemy::Progress()
{
	if (!act)
	{
		x = rand() % 60;
		y = rand() % 50;
		act = true;
	}

	if (act)
	{
		step++;
		if (step > maxStep)
		{
			step = 0;
			maxStep = rand() % 10 + 2;
			dir = GetRandomDir();
		}

		switch (dir)
		{
		case LEFT:
			x--;
			if (x < 0)
			{
				x++;
				dir = GetRandomDir();
			}
			break;
		case RIGHT:
			x++;
			if (x > 50)
			{
				x--;
				dir = GetRandomDir();
			}
			break;
		default:
			break;

		}

		for (int i = 0; i < BulletCount; i++)
		{
			Obj* bullet = ObjectPoolManager::Instance()->bullet[i];
			if (bullet->act)
			{
				if (CollisionManager::Instance()->CollisionCheck(this, bullet))
				{
					bullet->act = false;
					act = false;
				}
			}
		}

	}

	
}

void Enemy::Render()
{
	if (act)
	{
		DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
	}
	
}

void Enemy::Release()
{
}

Dir Enemy::GetRandomDir()
{
	switch (rand() % 2)
	{
	case 0:
		return LEFT;
	case 1:
		return RIGHT;
	}
}