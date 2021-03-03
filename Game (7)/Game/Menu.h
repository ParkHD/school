#pragma once
#include "Scene.h"
class Menu : public Scene
{
private:
	int count = 0;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

