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
}

void Enemy::Progress()
{
	if (!info.act)
	{
		info.x = rand() % 60;
		info.y = rand() % 50;
		info.act = true;
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