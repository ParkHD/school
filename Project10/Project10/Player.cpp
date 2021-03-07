#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "KeyManager.h"

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

}
   
void Player::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();


	if (dwKey & KEY_UP )
	{
		y--;
		Collision(UP);
	}
	if (dwKey & KEY_DOWN)
	{
		y++;
		Collision(DOWN);
	}
	if (dwKey & KEY_LEFT )
	{
		//if (!isGrounded)									// �߷����� ��������
		//{
		//	y++;
		//}
		x--;
		Collision(LEFT);
	}
	if (dwKey & KEY_RIGHT)
	{
		//if (!isGrounded)									// �߷����� ��������
		//{
		//	y++;
		//}
		x++;
		Collision(RIGHT);
	}

	if ((dwKey & KEY_SPACE) && isGrounded )
	{
		jump = true;
 		t = 0;
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
	
}

void Player::Render()
{
	for(int i = 0; i< 2; i++)
		DoubleBuffer::Instance()->WriteBuffer(x, y+i, p_shape[i], color);
}

void Player::Release()
{
}
