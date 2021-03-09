#include "Player.h"
#include "DoubleBuffer.h"
#include "ObjectPoolManager.h"
#include "KeyManager.h"
#include "Collision.h"
#include"SceneManager.h"
void Player::Initialize()
{
	x = 5;
	y = 5;
	p_shape[0] = "¡Ú¡Ú";
	p_shape[1] = "¡Ú¡Ú";
	color = ¹àÀºÃÊ·Ï»ö;


	t = 0.0f;
	h = 0;
	v0 = 0.0f;


	jump = false;
	isGrounded = false;
	isJump = false;

	health = 3;
	h_shape = "¢¾¢¾¢¾";
	count = 50;

	stun = false;
	stunTime = 0;

	hitTime = 0;
	hitDir = 0;

	act = true;
}
   
void Player::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();
	if (act) {
		if (!stun)
		{
		

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

			if ((dwKey & KEY_UP) && isGrounded)
			{
				jump = true;
				t = 0;
			}

			if (dwKey & KEY_SPACE)
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
		else if (!jump)
		{
			if (!isGrounded)									// Áß·ÂÀ¸·Î ¶³¾îÁú½Ã
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


		count++;
		if (count > 50)
		{
			p_shape[0] = "¡Ú¡Ú";
			p_shape[1] = "¡Ú¡Ú";
			hitTime = 0;
		}
		else if (count <= 50)
		{
			for (int i = 0; i < 5; i++) {
				if (ObjectPoolManager::Instance()->enemy[i]->act)
				{
					hitTime++;
					p_shape[0] = "¡Ù¡Ù";
					p_shape[1] = "¡Ù¡Ù";
					if ((x + 1 == ObjectPoolManager::Instance()->enemy[i]->x)
						&& y == ObjectPoolManager::Instance()->enemy[i]->y)
					{
						hitDir = 1;
					}
					else if ((x == ObjectPoolManager::Instance()->enemy[i]->x + 1)
						&& y == ObjectPoolManager::Instance()->enemy[i]->y)
					{
						hitDir = 0;
					}

					stunTime++;
					if (stunTime > 40)
					{
						stun = false;
						stunTime = 0;
					}
					if (hitTime < 4)
					{
						stunTime++;
						stun = true;

						y--;
						switch (hitDir)
						{
						case 1:
							x--;
							Collision(LEFT);
							break;
						case 0:
							x++;
							Collision(RIGHT);
							break;
						}
					}

				}
			}

		}
		for (int i = 0; i < 5; i++)
		{
			if (ObjectPoolManager::Instance()->enemy[i]->act) {
				if (Collision::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->enemy[i]->GetRect()))		// ÇÇ°Ý
				{
					if (count > 50)
					{
						health--;
						switch (health)
						{
						case 3:
							h_shape = "¢¾¢¾¢¾";

							break;
						case 2:
							h_shape = "¢¾¢¾¢½";

							break;
						case 1:
							h_shape = "¢¾¢½¢½";

							break;
						case 0:
							h_shape = "¢½¢½¢½";
							act = false;

							break;
						}
						count = 0;
					}
				}
			}
		}
	}
	if (!act)
	{
		if (dwKey & KEY_UP)
		{
			count = 0;
		}
		if (dwKey & KEY_DOWN)
		{
			count = 1;
		}
		if (dwKey & KEY_RETURN)
		{
			switch (count)
			{

			case 0:
				SceneManager::Instance()->Initialize(STAGE);
				break;
			case 1:
				SceneManager::Instance()->Initialize(MENU);
				break;
			}
		}
	}


}

void Player::Render()
{
	

	if (act)
	{
		for (int i = 0; i < 2; i++)
			DoubleBuffer::Instance()->WriteBuffer(x, y + i, p_shape[i], color);
	}

	DoubleBuffer::Instance()->WriteBuffer(3, 50, h_shape, ¹àÀº»¡°£»ö);
	if (!act)
	{
		switch (count)
		{
		case 0:
			DoubleBuffer::Instance()->WriteBuffer(22, 22, "¢º  RETRY", ¹àÀº»¡°£»ö);
			DoubleBuffer::Instance()->WriteBuffer(22, 25, "    MENU", ¹àÀº»¡°£»ö);
		
			break;
		case 1:
			DoubleBuffer::Instance()->WriteBuffer(22, 22, "    RETRY", ¹àÀº»¡°£»ö);
			DoubleBuffer::Instance()->WriteBuffer(22, 25, "¢º  MENU", ¹àÀº»¡°£»ö);

			break;
		}
	}

}

void Player::Release()
{
}
