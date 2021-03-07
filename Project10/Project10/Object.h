#pragma once
#include"Include.h"
class Object
{
public:
	int x;
	int y;
	Color color;
	bool act = true;

	bool rand;
	

public:
	virtual void Initialize() PURE;
	virtual void Progress() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

public:
	SMALL_RECT GetRect()
	{
		SMALL_RECT rect = {x, y, x + 1, y + 1 };
		return rect;
	}
	int Collision(DIR dir);
};

