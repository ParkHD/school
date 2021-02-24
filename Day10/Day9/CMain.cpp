#pragma once
#include "SceneManager.h"
#include"WindowController.h"
#include"DoubleBuffer.h"
int main()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->SetScene(LOGO);

	while (true)
	{
		system("cls");
		DoubleBuffer::Instance()->FlipBuffer();
		DoubleBuffer::Instance()->ClearBuffer();

		SceneManager::Instance()->Progress();
		SceneManager::Instance()->Render();
		Sleep(50);
	}

	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();
	return 0;
}