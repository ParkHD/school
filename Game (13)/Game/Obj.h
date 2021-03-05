#pragma once
#include "Include.h"
class Obj
{
public:
	int x;
	int y;
	Color color;
	const char* shape;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
};

