#pragma once
#include"Include.h"
class Scene
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};