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
