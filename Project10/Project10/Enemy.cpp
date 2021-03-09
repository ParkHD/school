#include "Enemy.h"
#include "Collision.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"

void Enemy::Initialize()
{
	x = 35;
	y = 35;
	color = ¹àÀº»¡°£»ö;

	shape_size = 2;
	e_shape[0] = "¡à¡à";
	e_shape[1] = "¡à¡à";

	t = 0.0f;
	h = y;
	v0 = 0.0f;

	step = 0;
	maxStep = 0;

	act = true;
	timeStep = 0;

	bubble = false;
	bubbleDir = 0;

	boom = 0;
}

void Enemy::Progress()
{
	timeStep++;
	if (timeStep > 10) 
	{
		if (act && !bubble)
		{
			
			for (int i = 0; i < 5; i++)
			{
				if (ObjectPoolManager::Instance()->bullet[i]->x >= x
					&& ObjectPoolManager::Instance()->bullet[i]->x <= x + 1
					&& ObjectPoolManager::Instance()->bullet[i]->y >= y
					&& ObjectPoolManager::Instance()->bullet[i]->y  <= y + 1)
				{

					e_shape[0] = " ¡Ü¡Ü";
					e_shape[1] = " ¡Ü¡Ü";

					bubbleDir = rand() % 2;
					bubble = true;

					color = ¹àÀº³ë¶õ»ö;

					switch (bubbleDir)
					{
					case 0:
						break;
					case 1:
						break;
					}
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



			/*step++;
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
			}*/

			if (y > 48)															// ±¸¸Û ¶³¾îÁ³À»¶§
				y = 3;

			
		}
		//else if (!act)														// Á×¾úÀ»¶§
		//{
		//	x = 3;
		//	y = 3;
		//	act = true;
		//}



		if (bubble)
		{
			boom++;

			if (ObjectPoolManager::Instance()->CheckMap(x, y - 1) == 1)
			{
				if (bubbleDir == 0)
				{
					x--;
					if (ObjectPoolManager::Instance()->CheckMap(x, y) == 1)
					{
						x++;
					}
				}
				else if (bubbleDir == 1)
				{
					x++;
					if (ObjectPoolManager::Instance()->CheckMap(x + 1, y) == 1)
					{
						x--;
					}
				}
			}
			else
			{
				y--;												// Ç³¼±À§·Î
			}

			if (y < 0)
			{
				y = 48;
			}

			if (boom >= 50)											// ½Ã°£¿À¹Ù ´Ù½Ã »ì¾Æ³²
			{
				color = »¡°£»ö;
				if (boom >= 70)
				{
					bubble = false;
					e_shape[0] = "¡à¡à";
					e_shape[1] = "¡à¡à";
					boom = 0;
				}
			}



			if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->player->GetRect()))		// Ç³¼±ÅÍÆ®¸²
			{
				act = false;
			}

	
		}
		timeStep = 0;
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



