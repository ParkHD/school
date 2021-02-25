#include "Enemy.h"

void Enemy::Initialize()
{
	x = 30;
	y = 30;
	color = ¹àÀº»¡°£»ö;
	shape = "Èª";

}

void Enemy::Progress()
{
	step++;
	if (step > maxStep)
	{
		step = 0;
		maxStep = rand() % 15 + 2;
		dir = GetRandomDir();
	}

	switch (dir)
	{
	case LEFT:
		x--;
		if (x < 0)
		{
			x++;
			dir = GetRandomDir();
		}
		break;
	case RIGHT:
		x++;
		if (x > 50)
		{
			x--;
			dir = GetRandomDir();
		}
		break;
	case UP:
		y--;
		if (y < 0)
		{
			y++;
			dir = GetRandomDir();
		}
		break;
	case DOWN:
		y++;
		if (y > 50)
		{
			y--;
			dir = GetRandomDir();
		}
		break;
	default:
		break;
	}

}

void Enemy::Render()
{

}

void Enemy::Release()
{
}
Dir Enemy::GetRandomDir()
{
	switch (rand() % 4)
	{
	case 0:
		return LEFT;
	case 1:
		return RIGHT;
	case 2:
		return UP;
	case 3:
		return DOWN;
	}
}

bool Enemy::Collider()
{




	return false;
}

