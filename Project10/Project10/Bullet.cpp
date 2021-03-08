#include "Bullet.h"
#include "ObjectPoolManager.h"
#include "DoubleBuffer.h"
void Bullet::Initialize()
{
	color = �����Ķ���;
	act = false;
	shape = "��";
	bulletDir = 0;

	x = 0;
	y = 0;

	count = 0;


}

void Bullet::Progress()
{

	if (act)
	{
		switch (bulletDir)
		{
		case 0:
			x--;

			break;
		case 1:
			x++;
			break;
		}
		if (ObjectPoolManager::Instance()->CheckMap(x, y) == 1)
			act = false;
	}




}


void Bullet::Render()
{
	if (act)
	{
		DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
	}
}

void Bullet::Release()
{
}
