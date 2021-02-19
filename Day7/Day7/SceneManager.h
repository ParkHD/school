#pragma once
#include "Scene.h"
class SceneManager
{
private:
	static SceneManager* instance;
public:
	static SceneManager* Instance();

private:
	Scene* currentScene;
public:
	void SetScene(int id);
	void Progress();
	void Render();
	void Release();
public:
	void SetCursorPosition(int x, int y);
	void SetCursorColor(int color);
	void SetCursorHandle();
public:
	SceneManager();
	~SceneManager();
};

