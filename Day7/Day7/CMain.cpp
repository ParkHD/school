#pragma once
#include "SceneManager.h"

int main()
{
	SceneManager::Instance()->SetCursorHandle();
	SceneManager::Instance()->SetScene(0);

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