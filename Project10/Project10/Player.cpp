#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "KeyManager.h"
#include "Collision.h"
void Player::Initialize()
{
	x = 5;
	y = 5;
	p_shape[0] = "�ڡ�";
	p_shape[1] = "�ڡ�";
	color = �����Ķ���;


	t = 0.0f;
	h = 0;
	v0 = 0.0f;


	jump = false;
	isGrounded = false;
	isJump = false;

	health = 3;
	h_shape = "������";
	test = " ";
	count = 3;

	stun = false;
}
   
void Player::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();

	if(!stun)
	{
		if (dwKey & KEY_UP)
		{
			y--;
			Collision(UP);
		}
		if (dwKey & KEY_DOWN)
		{
			y++;
			Collision(DOWN);
		}
		if (dwKey & KEY_LEFT)
		{
			bulletDir = 0;
			x--;
			Collision(LEFT);
		}
		if (dwKey & KEY_RIGHT)
		{
			bulletDir = 1;
			x++;
			Collision(RIGHT);
		}

		if ((dwKey & KEY_SPACE) && isGrounded)
		{
			jump = true;
			t = 0;
		}

		if (dwKey & KEY_RETURN)
		{
			for (int i = 0; i < 5; i++)
			{
				if (!(ObjectPoolManager::Instance()->bullet[i]->act))
				{
					switch (bulletDir)
					{
					case 0:
						ObjectPoolManager::Instance()->bullet[i]->x = x - 1;
						ObjectPoolManager::Instance()->bullet[i]->y = y;
						ObjectPoolManager::Instance()->bullet[i]->bulletDir = 0;
						break;
					case 1:
						ObjectPoolManager::Instance()->bullet[i]->x = x + 2;
						ObjectPoolManager::Instance()->bullet[i]->y = y;
						ObjectPoolManager::Instance()->bullet[i]->bulletDir = 1;
						break;
					}
					ObjectPoolManager::Instance()->bullet[i]->act = true;
					break;
				}
			}
		}
	}








	if (jump)									// ������ �߷����� ��������
	{
		v0 = 1.5f;
		t += 0.05f;
		float h = -v0 * t + (0.5 * G * t * t);
		if (h >= 2)
			h = 2;
		else if (h <= -2)
			h = -2;
		y += h; 


		if (h >= 0)
		{
			if (ObjectPoolManager::Instance()->CheckMap(x, y + 2) == 1
				|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 2) == 1
				&& (ObjectPoolManager::Instance()->CheckMap(x, y + 3) == 1
				|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 3) == 1))
			{
				jump = false;
				v0 = 0;
				t = 0;
				while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ���� �Ĺ�����
					|| ObjectPoolManager::Instance()->CheckMap(x, y + 1) == 1
					|| ObjectPoolManager::Instance()->CheckMap(x + 1, y) == 1
					|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 1) == 1)
				{

					y--;
				}
			}
		}
	}
	else if(!jump)
	{
		if(!isGrounded)									// �߷����� ��������
		{
			t += 1.0f;
			float h = 0.5 * G * t * t;
 		  	
			if (h >= 2)
				h = 2;
			else if (h <= -2)
				h = -2;
			y += h;
		}
		if (h >= 0)
		{
			if (ObjectPoolManager::Instance()->CheckMap(x, y + 2) == 1
				|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 2) == 1
				&& (ObjectPoolManager::Instance()->CheckMap(x, y + 3) == 1
					|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 3) == 1))
			{
				t = 0;
				while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ���� �Ĺ�����
					|| ObjectPoolManager::Instance()->CheckMap(x, y + 1) == 1
					|| ObjectPoolManager::Instance()->CheckMap(x + 1, y) == 1
					|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 1) == 1)
				{

					y--;
				}
			}
		}

	}
	if (((ObjectPoolManager::Instance()->CheckMap(x, y + 2) == 1
		|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 2) == 1)
		&& (ObjectPoolManager::Instance()->CheckMap(x, y + 3) == 1
			|| ObjectPoolManager::Instance()->CheckMap(x + 1, y + 3) == 1))
		&& (h >= 0))	 // ���� ������ 
	{
		isGrounded = true;
	}
	else
	{
		isGrounded = false;
	}
	if (y > 48)
	{
		y = 3;
	}


	count++;
	if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->enemy->GetRect()))		// ǳ����Ʈ��
	{
		if (count > 20)
		{
			if ((x + 1 == ObjectPoolManager::Instance()->enemy->x)
				&& y == ObjectPoolManager::Instance()->enemy->y)
			{
				test = "Right";
				
				x--;
				for (int i = 0; i < 20; i++)
				{
					stun = true;
				}
				stun = false;
			}
			else if ((x == ObjectPoolManager::Instance()->enemy->x + 1)
				&& y == ObjectPoolManager::Instance()->enemy->y)
			{
				test = "Left ";
				x++;
				for (int i = 0; i < 20; i++)
				{
					stun = true;
				}
				stun = false;
			}
				

			health--;
			switch (health)
			{
			case 3:
				h_shape = "������";

				break;
			case 2:
				h_shape = "������";

				break;
			case 1:
				h_shape = "������";

				break;
			case 0:
				h_shape = "������";
				act = false;
				break;
			}
			count = 0;
		}
		
		
	}
}

void Player::Render()
{
	for(int i = 0; i< 2; i++)
		DoubleBuffer::Instance()->WriteBuffer(x, y+i, p_shape[i], color);

	DoubleBuffer::Instance()->WriteBuffer(3, 50, h_shape, ����������);

	DoubleBuffer::Instance()->WriteBuffer(8, 50, test, ����������);
}

void Player::Release()
{
}
