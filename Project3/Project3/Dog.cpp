#include "Dog.h"

void Dog::Move()
{

	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
		if (x < 0)
		{
			x++;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		x++;
		if (x > 40)
		{
			x--;
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		y--;
		if (y < 0)
		{
			y++;
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
		if (y > 30)
		{
			y--;
		}
	}

	SetCursorColor(color);
	SetCursorPosition(x, y);
	cout << shape;
}


Dir Dog::GetRandomDir()
{
	switch (rand() % 4)
	{
	case 0:
		return LEFT;
	case 1:
		return RIGHT;
	case 2:
		return UP;
	case 3:
		return DOWN;
	}
}


void Dog::SetCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Dog::SetCursorColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Dog::SetCursorHandle()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

Dog::Dog()
{
	shape = "¤±¤Ð";
	x = rand() % 40;
	y = rand() % 30;
	color = (Color)(rand() % 14 + 1);
	dir = GetRandomDir();
	step = 0;
	maxStep = rand() % 5 + 5;
	SetCursorHandle();
}

Dog::Dog(const char* _shape, int _x, int _y, Color _color)
{
}

Dog::~Dog()
{
}
