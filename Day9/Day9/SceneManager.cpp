#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::instance = nullptr;

void SceneManager::SetScene(SCENE_ID id)
{
	if (currenScene != nullptr)
	{
		delete currenScene;
		currenScene = nullptr;
	}

	switch (id)
	{
	case LOGO:
		currenScene = new Logo;
		break;
	case MENU:
		currenScene = new Menu;
		break;
	case STAGE:
		currenScene = new Stage;
		break;
	default:
		break;
	}


	currenScene->Initialize();
}

void SceneManager::Progress()
{
	currenScene->Progress();
}

void SceneManager::Render()
{
	currenScene->Render();
}

void SceneManager::Release()
{
	currenScene->Release();
}

SceneManager::SceneManager()
{
	currenScene = nullptr;
}