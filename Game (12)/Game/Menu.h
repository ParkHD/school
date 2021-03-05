#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	Info menu;
	Info arrow;
	int index;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

