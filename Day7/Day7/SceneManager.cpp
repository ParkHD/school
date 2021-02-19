#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::instance = nullptr;
SceneManager* SceneManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new SceneManager;
	}

	return instance;
}

void SceneManager::SetScene(int id)
{
	if (currentScene != nullptr)
	{
		delete currentScene;										// 메모리 차지 방지
		currentScene = nullptr;										// 안써도 되지만 안전위해
	}

	switch (id)
	{
	case 0:
		currentScene = new Logo;
		break;
	case 1:
		currentScene = new Menu;
		break;
	case 2:
		currentScene = new Stage;
		break;
	default:
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

void SceneManager::SetCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SceneManager::SetCursorColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SceneManager::SetCursorHandle()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

SceneManager::SceneManager()
{
	currentScene = nullptr;
}

SceneManager::~SceneManager()
{
}

