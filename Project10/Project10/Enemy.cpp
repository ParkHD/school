#include "Enemy.h"
#include "Collision.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"

void Enemy::Initialize()
{
	x = 35;
	y = 35;
	color = ¹àÀº»¡°£»ö;

	shape_size = 3;
	e_shape[0] = "¡à¡à";
	e_shape[1] = "¡à¡à";
	e_shape[2] = "¤±    ";

	t = 0.0f;
	h = y;
	v0 = 0.0f;

	step = 0;
	maxStep = 0;

	act = true;
	timeStep = 0;

	bubble = false;
}

void Enemy::Progress()
{
	timeStep++;
	if (timeStep > 1) 
	{
		if (act && !bubble)
		{
			if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->player->GetRect()))
			{
				act = false;
			}
			for (int i = 0; i < 5; i++)
			{
				if (ObjectPoolManager::Instance()->bullet[i]->x >= x
					&& ObjectPoolManager::Instance()->bullet[i]->x <= x + 1
					&& ObjectPoolManager::Instance()->bullet[i]->y >= y
					&& ObjectPoolManager::Instance()->bullet[i]->y  <= y + 1)
				{
					/*act = false;
					ObjectPoolManager::Instance()->bullet[i]->act = false;*/
					
					e_shape[0] = " ¡Ü¡Ü¡Ü";
					e_shape[1] = "¡Ü¡Ü¡Ü¡Ü";
					e_shape[2] = " ¡Ü¡Ü¡Ü";
					bubble = true;
				}
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
					if (ObjectPoolManager::Instance()->CheckMap(x + 2, y) == 1)
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

			timeStep = 0;
		}
		else if (!act)
		{
			x = 3;
			y = 3;
			act = true;
		}
	}
	
}

void Enemy::Render()
{
	
	if (act)
	{
		for (int i = 0; i < shape_size; i++)
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



