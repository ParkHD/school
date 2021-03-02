#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"
void Menu::Initialize()
{

}

void Menu::Progress()
{
	switch (count)
	{
	case 0:
		if (GetAsyncKeyState(VK_RETURN))
		{
			SceneManager::Instance()->SetScene(STAGE);
		}
		break;
	case 1:
		break;
	case 2:
		break;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		count--;
		if (count < 0)
			count++;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		count++;
		if (count > 2)
			count--;
	}
}

void Menu::Render()
{
	switch (count)
	{
	case 0:
		DoubleBuffer::Instance()->WriteBuffer(10, 10, "¢º TITLE", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 20, "  Start", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 30, "  Exit", 13);
		break;
	case 1:
		DoubleBuffer::Instance()->WriteBuffer(10, 10, "  TITLE", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 20, "¢º Start", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 30, "  Exit", 13);
		break;
	case 2:
		DoubleBuffer::Instance()->WriteBuffer(10, 10, "  TITLE", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 20, "  Start", 13);
		DoubleBuffer::Instance()->WriteBuffer(10, 30, "¢º Exit", 13);
		break;
	}
}

void Menu::Release()
{
}
