#pragma once
#include "Obj.h"
class CollisionManager
{
private:
	static CollisionManager* instance;
public:
	static CollisionManager* Instance()
	{
		if (instance == nullptr)
		{
			instance = new CollisionManager;
		}

		return instance;
	}
public:
	bool CollisionCheck(Obj* objA, Obj* objB);
};

