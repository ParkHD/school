#pragma once
#include "Obj.h"
class Player :public Obj
{
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

