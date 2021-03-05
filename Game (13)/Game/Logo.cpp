#include "Logo.h"
#include "SceneManager.h"
#include "WindowController.h"

void Logo::Initialize()
{
}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Instance()->SetScene(MENU);
	}
	
}

void Logo::Render()
{
	WindowController::Instance()->SetCursorColor(¹àÀº³ë¶õ»ö);
	WindowController::Instance()->SetCursorPosition(10, 10);
	cout << "LOGO" << endl;
}

void Logo::Release()
{
}
