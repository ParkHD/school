#pragma once
#include "Obj.h"
class Player : public Obj
{
private:
	float t;
	int h;
	float v0;
	float G = 9.8f;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

