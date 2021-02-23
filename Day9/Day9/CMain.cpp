#pragma once
#include "SceneManager.h"
#include"WindowController.h"
int main()
{
	WindowController::Instance()->SetCursorHandle();
	SceneManager::Instance()->SetScene(LOGO);

	while (true)
	{
		system("cls");
		SceneManager::Instance()->Progress();
		SceneManager::Instance()->Render();
		Sleep(50);
	}

	SceneManager::Instance()->Release();

	return 0;
}