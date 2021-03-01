#include "Stage.h"
#include "Include.h"
#include "SceneManager.h"
void Stage::Initialize()
{
	player.Initialize();
}

void Stage::Progress()
{
	player.Progress();
}

void Stage::Render()
{
	player.Render();
}

void Stage::Release()
{
}
