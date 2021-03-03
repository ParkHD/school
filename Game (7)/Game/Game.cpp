#include "Game.h"
#include "KeyManager.h"

void Game::Initialize()
{
	DoubleBuffer::Instance()->InitBuffer();
	SceneManager::Instance()->SetScene(LOGO);
}

void Game::Progress()
{
	KeyManager::Instance()->CheckKey(); // Ãß°¡

	DoubleBuffer::Instance()->FlipBuffer();
	DoubleBuffer::Instance()->ClearBuffer();

	SceneManager::Instance()->Progress();

}

void Game::Render()
{
	SceneManager::Instance()->Render();
}

void Game::Release()
{

	SceneManager::Instance()->Release();
	DoubleBuffer::Instance()->DestroyBuffer();
}
