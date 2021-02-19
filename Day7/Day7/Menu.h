#pragma once
#include "Scene.h"
class Menu : 
    public Scene
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

