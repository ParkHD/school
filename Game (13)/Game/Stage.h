#pragma once
#include "Scene.h"
#include "Obj.h"
class Stage : public Scene
{
private:
	Obj* player;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};



