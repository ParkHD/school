#include "Player.h"
#include "ObjectPoolManager.h"
#include "CollisionManager.h"
#include "KeyManager.h"

void Player::Initialize()
{
	info.x = 10;
	info.y = 10;
	info.color = ¹àÀº³ë¶õ»ö;
	info.shape[0] = "¡à¡à¡à¡à";
	info.shape[1] = "¡à¡à¡à¡à";
	info.shape[2] = "¡à¡à¡à¡à";
	info.act = true;	
}

void Player::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();

	if (dwKey & KEY_LEFT)
	{
		info.x--;

		if (ObjectPoolManager::Instance()->CheckMap(info.x, info.y) == 1
			|| ObjectPoolManager::Instance()->CheckMap(info.x, info.y+2) == 1
			)
		{
			info.x++;
		}
	}
	if (dwKey & KEY_RIGHT)
	{
		info.x++;

		if (ObjectPoolManager::Instance()->CheckMap(info.x+3, info.y+2) == 1
			|| ObjectPoolManager::Instance()->CheckMap(info.x + 3, info.y) == 1)
		{
			info.x--;
		}
	}
	if (dwKey & KEY_UP)
	{
		info.y--;

		if (ObjectPoolManager::Instance()->CheckMap(info.x, info.y) == 1
			|| ObjectPoolManager::Instance()->CheckMap(info.x + 3, info.y) == 1)
		{
			info.y++;
		}
	}
	if (dwKey & KEY_DOWN)
	{
		info.y++;

		if (ObjectPoolManager::Instance()->CheckMap(info.x+3, info.y+2) == 1
			|| ObjectPoolManager::Instance()->CheckMap(info.x, info.y + 2) == 1)
		{
			info.y--;
		}
	}

	if (dwKey & KEY_SPACE)
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!(ObjectPoolManager::Instance()->bullet[i]->info.act))
			{
				ObjectPoolManager::Instance()->bullet[i]->info.x = info.x;
				ObjectPoolManager::Instance()->bullet[i]->info.y = info.y;
				ObjectPoolManager::Instance()->bullet[i]->info.act = true;
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
