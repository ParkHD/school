#pragma once
#include "Include.h"

class WindowController
{
private:
	static WindowController* instance;
public:
	static WindowController* Instance()
	{
		if (instance == nullptr)
		{
			instance = new WindowController;
		}

		return instance;
	}
public:
	void SetCursorPosition(int x, int y);
	void SetCursorColor(int color);
	void SetCursorHandle();
};

