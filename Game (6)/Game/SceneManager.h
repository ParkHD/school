#pragma once
#include "Scene.h"
#include "Singleton.h"
class SceneManager : public Singleton<SceneManager>
{
private:
	Scene* currentScene;
public:
	void SetScene(SCENE_ID id);
	void Progress();
	void Render();
	void Release();
public:
	SceneManager();
};

