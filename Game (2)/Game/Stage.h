#pragma once
#include "Scene.h"
#include "ObjectFactory.h"

class Stage : public Scene
{
private:
	Obj* player;
	Obj* enemy;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};



