#pragma once
#include "Object.h"
class Collision
{
private:
	static Collision* instance;
public:
	static Collision* Instance()
	{
		if (instance == nullptr)
			instance = new Collision;
		return instance;
	}

public:
	bool CollisionCheck(SMALL_RECT rectA, SMALL_RECT rectB);

};

