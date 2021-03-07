#include "Stage.h"
#include "Include.h"
#include "ObjectPoolManager.h"
void Stage::Initialize()
{
	ObjectPoolManager::Instance()->Initialize();
}

void Stage::Progress()
{
	ObjectPoolManager::Instance()->Progress();
}

void Stage::Render()
{
	ObjectPoolManager::Instance()->Render();
}

void Stage::Release()
{
	ObjectPoolManager::Instance()->Release();
}
