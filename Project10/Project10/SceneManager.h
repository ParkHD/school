#pragma once
#include "Scene.h"
#include "Include.h"

class SceneManager
{
private:
	static SceneManager* instance;
public:
	static SceneManager* Instance()
	{
		if (instance == nullptr)
			instance = new SceneManager;
		return instance;
	}
	
public:
	Scene* currentScene;
public:
	void Initialize(STEP id);
	void Progress();
	void Render();
	void Release();

	SceneManager()
	{
		currentScene = nullptr;
	}
};

