#pragma once
#include "Obj.h"
#include "Singleton.h"
class CollisionManager : public Singleton<CollisionManager>
{

public:
	bool CollisionCheck(Obj* objA, Obj* objB);
};

