#include "Stage.h"
#include "SceneManager.h"

void Stage::Initialize()
{
}

void Stage::Progress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Instance()->SetScene(0);
	}
}

void Stage::Render()
{
	cout << "STAGE" << endl;
}

void Stage::Release()
{
}
