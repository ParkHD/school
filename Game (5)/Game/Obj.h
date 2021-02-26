#pragma once
#include "DoubleBuffer.h"
class Obj
{
public:
	bool act;
	int x;
	int y;
	Color color;
	const char* shape;

	int count;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()
	{
		if (act)
		{
			DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
		}
	}
	virtual void Release()PURE;
};

