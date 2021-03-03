#include "Bullet.h"

void Bullet::Initialize()
{
	info.act = false;
	info.x = 0;
	info.y = 0; 
	info.color = ¹àÀºÆÄ¶õ»ö;
	info.shape[0] = "¡Ü";
}

void Bullet::Progress()
{
	if (info.act)
	{
		info.x++;
		if (info.x >= 60)
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
