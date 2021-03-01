#include "Player.h"
#include"DoubleBuffer.h"
void Player::Initialize()
{
	x = 10;
	y = 10;
	shape = "¿Ê";
	color = ¹àÀºÆÄ¶õ»ö;
}

void Player::Progress()
{
	if (GetAsyncKeyState(VK_UP))
	{
		y--;
		if (y < 0)
			y++;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
		if (y > 40)
			y--;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
		if (x < 0)
			x++;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (x > 40)
			x--;
		x++;
	}
}

void Player::Render()
{
	DoubleBuffer::Instance()->WriteBuffer(x, y, shape, color);

}

void Player::Release()
{
}
