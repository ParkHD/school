#pragma once
#include "Scene.h"
class SceneManager
{
private:
	static SceneManager* instance;
public:
	static SceneManager* Instance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager;
		}

		return instance;
	}
private:
	Scene* currenScene;
public:
	void SetScene(SCENE_ID id);
	void Progress();
	void Render();
	void Release();
public:
	SceneManager();
};

