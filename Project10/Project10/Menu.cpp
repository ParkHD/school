#include "Menu.h"
#include"Include.h"
#include"SceneManager.h"
#include"DoubleBuffer.h"
void Menu::Initialize()
{
}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::Instance()->Initialize(STAGE);
	}
}

void Menu::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(10, 10, "Menu", 13);
}

void Menu::Release()
{
}
