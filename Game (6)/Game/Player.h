#pragma once
#include "Obj.h"
class Player : public Obj
{
	Obj* bullet;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

