#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "WindowController.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::Initialize(STEP id)
{
	WindowController::Instance()->SetCursorHandle();

	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
	switch (id)
	{
	case LOGO:
		currentScene = new Logo;
		break;
	case MENU:
		currentScene = new Menu;
		break;
	case STAGE:
		currentScene = new Stage;
		break;
	}

	currentScene->Initialize();
}

void SceneManager::Progress()
{
	currentScene->Progress();
}

void SceneManager::Render()
{
	currentScene->Render();
}

void SceneManager::Release()
{
	currentScene->Release();
}
