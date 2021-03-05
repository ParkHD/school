#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "KeyManager.h"

void Menu::Initialize()
{
	menu.color = Èò»ö;
	menu.x = 30;
	menu.y = 30;
	menu.shape[0] = "START";
	menu.shape[1] = "OPTION";
	menu.shape[2] = "EXIT";

	arrow.color = ³ë¶õ»ö;
	arrow.x = menu.x - 5;
	arrow.y = menu.y;
	arrow.shape[0] = "¢º";

	index = 0;
}

void Menu::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();

	if (dwKey & KEY_UP)
	{
		if (arrow.y > menu.y)
		{
			arrow.y-=2;
			index--;
		}
	}

	if (dwKey & KEY_DOWN)
	{
		if (arrow.y < menu.y + 4)
		{
			arrow.y += 2;
			index++;
		}
	}

	if (dwKey & KEY_RETURN)
	{
		switch (index)
		{
		case 0:
			SceneManager::Instance()->SetScene(STAGE);
			break;
		default:
			break;
		}
	}
}

void Menu::Render()
{
	for (int i = 0; i < ObjHeight; i++)
	{
		DoubleBuffer::Instance()->WriteBuffer(menu.x, menu.y + (2 * i), menu.shape[i], menu.color);
	}

	DoubleBuffer::Instance()->WriteBuffer(arrow.x, arrow.y, arrow.shape[0], arrow.color);
}

void Menu::Release()
{
}
