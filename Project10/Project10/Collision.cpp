#include "Collision.h"

Collision* Collision::instance = nullptr;

bool Collision::CollisionCheck(SMALL_RECT rectA, SMALL_RECT rectB)
{
	if (rectA.Left <= rectB.Right && rectA.Right >= rectB.Left &&
		rectA.Top <= rectB.Bottom && rectA.Bottom >= rectB.Top)
	{
		return true;
	}
	return false;
}
