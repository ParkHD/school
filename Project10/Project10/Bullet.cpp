#include "Bullet.h"
#include "ObjectPoolManager.h"
#include "DoubleBuffer.h"
void Bullet::Initialize()
{
	color = ¹àÀºÆÄ¶õ»ö;
	act = false;
	shape = "¡Û";
	bulletDir = 0;

	x = 0;
	y = 0;

	count = 0;


}

void Bullet::Progress()
{
	count++;
	if (count > 20)
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

		}
		count = 0;
	}
	if (ObjectPoolManager::Instance()->CheckMap(x, y) == 1)
		act = false;

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
