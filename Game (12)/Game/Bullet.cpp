#include "Bullet.h"
#include "ObjectPoolManager.h"

void Bullet::Initialize()
{
	info.act = false;
	info.x = 0;
	info.y = 0; 
	info.color = ¹àÀºÆÄ¶õ»ö;
	info.shape[0] = "¡Ü";
	info.dir = RIGHT;
}

void Bullet::Progress()
{
	if (info.act)
	{
		switch (info.dir)
		{
		case LEFT:
			info.x--;
			break;
		case UP:
			info.y--;
			break;
		case RIGHT:
			info.x++;
			break;
		case DOWN:
			info.y++;
			break;
		default:
			break;
		}
		
		if (ObjectPoolManager::Instance()->CheckMap(info.x, info.y) == 1)
		{
			info.x = 0;
			info.y = 0;
			info.act = false;
		}
	}
	
}

void Bullet::Render()
{
	if (info.act)
	{
		DoubleBuffer::Instance()->WriteBuffer(info.x, info.y, info.shape[0], info.color);
	}

}

void Bullet::Release()
{
}
