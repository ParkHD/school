#include "Player.h"
#include "WindowController.h"
void Player::Initialize()
{
	x = 10;
	y = 30;
	color = ¹àÀº³ë¶õ»ö;
	shape = "¿Ê";

	t = 0.0f;

	h = y;
	v0 = 10.0f;
}

void Player::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		t = 0;
		y = 29;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		x++;
	}

	if (y >= 30)
	{
		y = 30;
		t = 0;
	}
	else
	{
		t += 0.1f;
		// -(V0 * t) +(0.5f * G * t * t)
		h = -(v0 * t) + (0.5f * G * t * t);
		y += h;
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