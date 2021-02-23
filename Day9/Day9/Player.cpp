#include "Player.h"
#include"WindowController.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	color = ���������;
	shape = "��";
}

void Player::Progress()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		x++;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
	}
}

void Player::Render()
{
	WindowController::Instance()->SetCursorColor(color);
	WindowController::Instance()->SetCursorPosition(x, y);
	cout << shape << endl;
}

void Player::Release()
{
}

