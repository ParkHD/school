#include "Player.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "KeyManager.h"
#include "Include.h"
void Player::Initialize()
{
	info.x = 2;
	info.y = 2;
	info.color = ¹àÀº³ë¶õ»ö;
	info.shape[0] = "¡à¡à¡à¡à";
	info.shape[1] = "¡à¡à¡à¡à";
	info.shape[2] = "¡à¡à¡à¡à";
	info.act = true;	
	info.dir = RIGHT;



}
int Player::collision(DIR dir)
{
	int left = info.x;
	int right = info.x + 3;
	int Up = info.y;
	int Down = info.y + 2;
	
	for (int i = left; i < right + 1; i++)
	{
		for (int j = Up; j < Down + 1; j++)
		{
			if (ObjectPoolManager::Instance()->CheckMap(i, j) == 1)
			{
				switch (dir)
				{
				case LEFT:
					return info.x++;
					break;
				case UP:
					return info.y++;
					break;
				case DOWN:
					return info.y--;
					break;
				case RIGHT:
					return info.x--;
					break;
				}
			}
		}
	}
}


void Player::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();
	if (aact)
	{
		if (dwKey & KEY_LEFT)
		{
			info.x--;
			collision(LEFT);
			info.dir = LEFT;
		}
		if (dwKey & KEY_RIGHT)
		{
			info.x++;
			collision(RIGHT);
			info.dir = RIGHT;
		}
		if (dwKey & KEY_UP)
		{
			info.y--;
			collision(UP);
			info.dir = UP;
		}
		if (dwKey & KEY_DOWN)
		{
			info.y++;
			collision(DOWN);
			info.dir = DOWN;

		}
	}
	

	if (dwKey & KEY_SPACE)
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!(ObjectPoolManager::Instance()->bullet[i]->info.act))
			{
				int x = 0;
				int y = 0;

				switch (info.dir)
				{
				case LEFT:
					y += 1;
					break;
				case UP:
					x += 2;
					break;
				case RIGHT:
					x += 3;
					y += 1;
					break;
				case DOWN:
					x += 2;
					y += 2;
					break;
				default:
					break;
				}

				ObjectPoolManager::Instance()->bullet[i]->info.x = info.x + x;
				ObjectPoolManager::Instance()->bullet[i]->info.y = info.y + y;
				ObjectPoolManager::Instance()->bullet[i]->info.act = true;
				ObjectPoolManager::Instance()->bullet[i]->info.dir = info.dir;
				break;
			}

		}

	}

	if (CollisionManager::Instance()->CollisionCheck(this->GetRect(), ObjectPoolManager::Instance()->enemy->GetRect()))
	{
		ObjectPoolManager::Instance()->enemy->info.act = false;
	}
}

void Player::Render()
{
	if (info.act)
	{
		for (int i = 0; i < ObjHeight; i++)
		{
			DoubleBuffer::Instance()->WriteBuffer(info.x, info.y + i, info.shape[i], info.color);
		}
	
	}

}

void Player::Release()
{
}

