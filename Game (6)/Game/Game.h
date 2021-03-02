#pragma once
#include "SceneManager.h"
#include "DoubleBuffer.h"

class Game
{
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

