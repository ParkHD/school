#include "Bullet.h"

void Bullet::Initialize()
{
	act = false;
	x = 0;
	y = 0; 
	color = ¹àÀºÆÄ¶õ»ö;
	shape = "¡Ü";
}

void Bullet::Progress()
{
	if (act)
	{
		if (count == 0)
		{
			x--;
			if (x <= 0)
			{
				x = 0;
				y = 0;
				act = false;
			}
		}
		if (count == 1)
		{
			x++;
			if (x >= 50)
			{
				x = 0;
				y = 0;
				act = false;
			}
		}


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
