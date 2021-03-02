#pragma once
#include "Include.h"
#include "Singleton.h"

class WindowController : Singleton<WindowController>
{

public:
	void SetCursorPosition(int x, int y);
	void SetCursorColor(int color);
	void SetCursorHandle();
};

