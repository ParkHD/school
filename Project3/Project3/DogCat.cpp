#pragma once
#include "Cat.h"
#include "Dog.h"
#include "Rat.h"

int main()
{
	Rat rat[3];
	Cat cat[3];
	//Dog dog;
	while (true)
	{
		system("cls");

		//dog.Move();
		//for (int i = 0; i < 1; i++)
		//{
		//	cat[i].Move();
		//	if (dog.x == cat[i].x && dog.y == cat[i].y)
		//	{
		//		cat[i].act = false;
		//	}
		//}


		for (int i = 0; i < 3; i++)
		{
			cat[i].Move();
			rat[i].Move();
			for (int j = 0; j < 3; j++)
			{
				if (rat[i].x == cat[j].x && rat[i].y == cat[j].y)
				{
					rat[i].act = false;
				}
			}
		}


		Sleep(50);
	}

	return 0;
}

