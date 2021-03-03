#pragma once
#include "DoubleBuffer.h"
class Obj
{

public:
	Info info;
public:
	SMALL_RECT GetRect()
	{
		SMALL_RECT rect = { info.x, info.y, info.x + ObjWidth, info.y + ObjHeight };
		return rect;
	}
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render() PURE;
	virtual void Release()PURE;
};

