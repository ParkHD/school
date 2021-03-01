#pragma once
#include "Scene.h"
#include "Player.h"
class Stage :
    public Scene
{
public:
	Player player;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};

