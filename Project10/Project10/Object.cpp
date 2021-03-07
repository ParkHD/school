#include "Object.h"
#include "ObjectPoolManager.h"

int Object::Collision(DIR dir)
{
	int left = x;
	int right = x + 1;
	int Up = y;
	int Down = y + 1;

	for (int i = left; i < right + 1; i++)
	{
		for (int j = Up; j < Down + 1; j++)
		{
			if (ObjectPoolManager::Instance()->CheckMap(i, j) == 1)
			{
				switch (dir)
				{
				case LEFT:
					return x++;
					break;
				case UP:
					return y++;
					break;
				case DOWN:
					return y--;
					rand = true;
					break;
				case RIGHT:
					return x--;
					break;
				}
			}
		}
	}
}
