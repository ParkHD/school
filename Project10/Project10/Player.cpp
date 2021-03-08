#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "KeyManager.h"

void Player::Initialize()
{
	x = 5;
	y = 5;
	p_shape[0] = "¡Ú¡Ú";
	p_shape[1] = "¡Ú¡Ú";
	color = ¹àÀºÆÄ¶õ»ö;


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

	if ((dwKey & KEY_SPACE) && isGrounded )
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







	if (jump)									// Á¡ÇÁÈÄ Áß·ÂÀ¸·Î ¶³¾îÁú‹š
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
				while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ¶¥¿¡ ÃÄ¹ÚÈú¶§
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
		if(!isGrounded)									// Áß·ÂÀ¸·Î ¶³¾îÁú½Ã
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
				while (ObjectPoolManager::Instance()->CheckMap(x, y) == 1					// ¶¥¿¡ ÃÄ¹ÚÈú¶§
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
		&& (h >= 0))	 // ¶¥¿¡ ÀÖÀ»¶§ 
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
}

void Player::Render()
{
	for(int i = 0; i< 2; i++)
		DoubleBuffer::Instance()->WriteBuffer(x, y+i, p_shape[i], color);
}

void Player::Release()
{
}
