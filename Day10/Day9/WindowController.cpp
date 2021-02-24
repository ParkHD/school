#include "WindowController.h"

WindowController* WindowController::instance = nullptr;

void WindowController::SetCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void WindowController::SetCursorColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void WindowController::SetCursorHandle()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

}