#include "Logo.h"
#include"Include.h"
#include"SceneManager.h"
#include"WindowController.h"
#include "DoubleBuffer.h"

void Logo::Initialize()
{
}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::Instance()->Initialize(MENU);
	}
}

void Logo::Render()
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
				if(y<25)
					DoubleBuffer::Instance()->WriteBuffer(x, y, "■", 밝은파란색);
				else
					DoubleBuffer::Instance()->WriteBuffer(x, y, "■", 밝은초록색);
				break;
			default:
				break;
			}
		}
	}
}

void Logo::Release()
{
}
