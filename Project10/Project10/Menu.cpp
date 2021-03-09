#include "Menu.h"
#include"Include.h"
#include"SceneManager.h"
#include"DoubleBuffer.h"
#include"KeyManager.h"

void Menu::Initialize()
{
	count = 0;
}

void Menu::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();

	if (dwKey & KEY_UP)
	{
		count--;
		if (count < 0)
			count = 0;
	}
	if (dwKey & KEY_DOWN)
	{
		count++;
		if (count > 1)
			count = 1;
	}

	if (dwKey & KEY_RETURN)
	{
		switch (count)
		{

		case 0:
			SceneManager::Instance()->Initialize(LOGO);
			break;
		case 1:
			SceneManager::Instance()->Initialize(STAGE);
			break;
		}
	}


}

void Menu::Render()
{
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			switch (map[y][x])
			{
			case 1:
				break;
			case 0:
				if (y < 25)
					DoubleBuffer::Instance()->WriteBuffer(x, y, "¡á", ¹àÀºÆÄ¶õ»ö);
				else
					DoubleBuffer::Instance()->WriteBuffer(x, y, "¡á", ¹àÀºÃÊ·Ï»ö);
				break;
			default:
				break;
			}
		}
	}
	switch (count)
	{
	case 0:
		DoubleBuffer::Instance()->WriteBuffer(25, 40, "¢º LOGO", 13);
		DoubleBuffer::Instance()->WriteBuffer(25, 45, "   Start", 13);

	
		break;
	case 1:
		DoubleBuffer::Instance()->WriteBuffer(25, 40, "   LOGO", 13);
		DoubleBuffer::Instance()->WriteBuffer(25, 45, "¢º Start", 13);
	
		break;
	}
}

void Menu::Release()
{
}
