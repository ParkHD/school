#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = nullptr;

bool CollisionManager::CollisionCheck(Obj* objA, Obj* objB)
{
	if (objA->info.x == objB->info.x && objA->info.y == objB->info.y)
	{
		return true;
	}

    return false;
}

bool CollisionManager::CollisionCheck(SMALL_RECT rectA, SMALL_RECT rectB)
{
	if (rectA.Left < rectB.Right && rectA.Right > rectB.Left &&
		rectA.Top < rectB.Bottom && rectA.Bottom > rectB.Top)
	{
		return true;
	}
	return false;
}

bool CollisionManager::CollisionCheck(int aX, int aY, int bX, int bY)
{
	if (aX == bX && aY == bY)
	{
		return true;
	}

	return false;
}

bool CollisionManager::CollisionCheck(SMALL_RECT rect, int x, int y)
{
	if (rect.Left <= x && rect.Right > x &&	rect.Top <= y && rect.Bottom > y )
	{
		return true;
	}
	return false;
}
