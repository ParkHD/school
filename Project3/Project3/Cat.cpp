#include "Cat.h"

void Cat::Move()
{
	if (act)
	{
		step++;
		if (step > maxStep)
		{
			step = 0;
			maxStep = rand() % 10 + 2;
			dir = GetRandomDir();
		}

		switch (dir)
		{
		case LEFT:
			x--;
			if (x < 0)
			{
				x++;
				dir = GetRandomDir();
			}
			break;
		case RIGHT:
			x++;
			if (x > 40)
			{
				x--;
				dir = GetRandomDir();
			}
			break;
		case UP:
			y--;
			if (y < 0)
			{
				y++;
				dir = GetRandomDir();
			}
			break;
		case DOWN:
			y++;
			if (y > 30)
			{
				y--;
				dir = GetRandomDir();
			}
			break;
		default:
			break;
		}

		SetCursorColor(color);
		SetCursorPosition(x, y);
		cout << shape;

	}
	else
	{
		x = rand() % 40;
		y = rand() % 30;
		color = (Color)(rand() % 14 + 1);
		dir = GetRandomDir();
		step = 0;
		maxStep = rand() % 5 + 5;
		act = true;
	}


}

Dir Cat::GetRandomDir()
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

void Cat::SetCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Cat::SetCursorColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Cat::SetCursorHandle()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}



Cat::Cat()
{
	shape = "¤²¤Ð";
	x = rand() % 40;
	y = rand() % 30;
	color = (Color)(rand() % 14 + 1);
	dir = GetRandomDir();
	step = 0;
	maxStep = rand() % 5 + 5;
	SetCursorHandle();
}

Cat::Cat(const char* _shape, int _x, int _y, Color _color)
{
	shape = _shape;
	x = _x;
	y = _y;
	color = _color;
	dir = GetRandomDir();
	SetCursorHandle();
}

Cat::~Cat()
{
}