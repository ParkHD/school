#include "Enemy.h"
#include "Collision.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"

void Enemy::Initialize()
{
	x = 35;
	y = 35;
	color = ¹àÀº»¡°£»ö;

	e_shape[0] = "¡à¡à";
	e_shape[1] = "¡à¡à";

	t = 0.0f;
	h = y;
	v0 = 0.0f;

	step = 0;
	maxStep = 0;
}

void Enemy::Progress()
{
	
	if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->player->GetRect()))
	{
		act = false;
	}

	if (ObjectPoolManager::Instance()->CheckMap(x, y + 2) == 1
		|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 2) == 1)		// ¶¥¿¡ ÀÖÀ»¶§ 
	{
		t = 0;
		isGrounded = true;
	}
	else
	{
		isGrounded = false;
	}

	if (!isGrounded)
	{
		t += 0.03f;
		float h = 0.5 * G * t * t;
		y += h;
		if (h > 2)																// Áß·Â ¼öÄ¡Á¦ÇÑ
		{
			h = 2;
		}
		else if (h < -2)
		{
			h = -2;
		}
	}
	while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ¶¥¿¡ ÃÄ¹ÚÈú¶§
		|| ObjectPoolManager::Instance()->CheckMap(x, y + 1) == 1
		|| ObjectPoolManager::Instance()->CheckMap(x + 1, y) == 1
		|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 1) == 1)
	{
		y--;
	}



	step++;
	if (step > maxStep)
	{
		maxStep = rand() % 10 + 5;
		dir = GetRandomDirection();
		step = 0;
	}

	if (isGrounded)
	{
		switch (dir)
		{
		case 0:
			if (ObjectPoolManager::Instance()->CheckMap(x - 1, y) == 1)
			{
				break;
			}
			else
			{
				x--;
				Collision(LEFT);
			}

			break;
		case 1:
			if (ObjectPoolManager::Instance()->CheckMap(x + 2 , y) == 1)
			{
				break;
			}
			else
			{
				x++;
				Collision(RIGHT);
			}

			break;
		}
	}

	if (y > 48)															// ±¸¸Û ¶³¾îÁ³À»¶§
		y = 3;
}

void Enemy::Render()
{
	
	if (act)
	{
		for (int i = 0; i < 2; i++)
		{
			DoubleBuffer::Instance()->WriteBuffer(x, y + i, e_shape[i], color);
		}
	}

}

void Enemy::Release()
{

}

DIR Enemy::GetRandomDirection()
{
	int randValue = rand() % 2;

	return (DIR)randValue;
}



