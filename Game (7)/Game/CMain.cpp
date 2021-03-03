#pragma once
#include "Game.h"

int main()
{
	Game game;
	game.Initialize();

	ULONGLONG ullTime = GetTickCount64();

	while (true)
	{		
		if (ullTime + 50 <= GetTickCount64())
		{
			ullTime = GetTickCount64();
			game.Progress();
			game.Render();
		}
	}

	game.Release();
	return 0;
}