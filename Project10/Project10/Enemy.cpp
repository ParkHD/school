#include "Enemy.h"
#include "Collision.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"

void Enemy::Initialize()
{
	x = 35;
	y = 35;
	color = ����������;

	shape_size = 2;
	e_shape[0] = "���";
	e_shape[1] = "���";

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

					e_shape[0] = " �ܡ�";
					e_shape[1] = " �ܡ�";

					bubbleDir = rand() % 2;
					bubble = true;

					color = ���������;

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
				|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 2) == 1)		// ���� ������ 
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
				if (h > 2)																// �߷� ��ġ����
				{
					h = 2;
				}
				else if (h < -2)
				{
					h = -2;
				}
			}
			while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ���� �Ĺ�����
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

			if (y > 48)															// ���� ����������
				y = 3;

			
		}
		//else if (!act)														// �׾�����
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
				y--;												// ǳ������
			}

			if (y < 0)
			{
				y = 48;
			}

			if (boom >= 50)											// �ð����� �ٽ� ��Ƴ�
			{
				color = ������;
				if (boom >= 70)
				{
					bubble = false;
					e_shape[0] = "���";
					e_shape[1] = "���";
					boom = 0;
				}
			}



			if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->player->GetRect()))		// ǳ����Ʈ��
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



