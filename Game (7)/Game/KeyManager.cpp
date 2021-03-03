#include "KeyManager.h"

void KeyManager::CheckKey()
{
	dwKey = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		dwKey |= KEY_UP; // 1
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		dwKey |= KEY_DOWN; // 2
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		dwKey |= KEY_LEFT; // 4
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		dwKey |= KEY_RIGHT; // 8
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		dwKey |= KEY_SPACE; // 16
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		dwKey |= KEY_RETURN; // 32
	}
}
