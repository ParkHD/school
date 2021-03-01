#pragma once
#include"Include.h"
class Object
{
public:
	int x;
	int y;
	Color color;
	const char* shape;
public:
	virtual void Initialize() PURE;
	virtual void Progress() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

