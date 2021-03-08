#pragma once
#include "Object.h"
class Bullet : public Object
{
private:
	const char* shape;
	int count;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

