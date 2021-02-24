#pragma once
#include "Scene.h"
class Menu : public Scene
{
private:
	const char* character[];
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};