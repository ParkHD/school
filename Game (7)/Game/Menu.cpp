#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "KeyManager.h"
void Menu::Initialize()
{

}

void Menu::Progress()
{

	DWORD dwKey = KeyManager::Instance()->GetKey();

	switch (count)
	{
	case 0:

		break;
	case 1:
		if (dwKey & KEY_RETURN)
		{
			SceneManager::Instance()->SetScene(STAGE);
		}
		break;
	case 2:
		break;
	}

	if (dwKey & KEY_UP)
	{
		count--;
		if (count < 0)
			count++;
	}
	if (dwKey & KEY_DOWN)
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
