#include "Logo.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "KeyManager.h"

void Logo::Initialize()
{
	
}

void Logo::Progress()
{
	DWORD dwKey = KeyManager::Instance()->GetKey();

	if (dwKey & KEY_RETURN)
	{
		SceneManager::Instance()->SetScene(MENU);
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
			case 0:
				break;
			case 1:
				DoubleBuffer::Instance()->WriteBuffer(x, y, "бс", 13);
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
