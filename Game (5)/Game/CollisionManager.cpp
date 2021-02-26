#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = nullptr;

bool CollisionManager::CollisionCheck(Obj* objA, Obj* objB)
{
	if (objA->x == objB->x && objA->y == objB->y)
	{
		return true;
	}

    return false;
}
