#pragma once
#include "Obj.h"
#include "Singleton.h"
class CollisionManager : public Singleton<CollisionManager>
{
public:
	bool CollisionCheck(Obj* objA, Obj* objB); // ObjA, ObjB
	bool CollisionCheck(SMALL_RECT rectA, SMALL_RECT rectB);
	bool CollisionCheck(int aX, int aY, int bX, int bY);
	bool CollisionCheck(SMALL_RECT rect, int x, int y);
};
