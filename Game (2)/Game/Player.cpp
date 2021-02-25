#include "Player.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	color = ¹àÀº³ë¶õ»ö;
	shape = "¿Ê";
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
	DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);
}

void Player::Release()
{
}
