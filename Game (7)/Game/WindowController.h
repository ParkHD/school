#pragma once
#include "Singleton.h"

class WindowController : public Singleton<WindowController>
{
public:
	void SetCursorPosition(int x, int y);
	void SetCursorColor(int color);
	void SetCursorHandle();
};

