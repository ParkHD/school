#pragma once
#include "Include.h"
class Rat
{
public:
	bool act;
	const char* shape;
	int x;
	int y;
	Color color;
	Dir dir;
	int step;
	int maxStep;
public:
	void Move();
private:
	void SetCursorPosition(int x, int y);
	void SetCursorColor(int color);
	void SetCursorHandle();
	Dir GetRandomDir();
public:
	Rat();
	Rat(const char* _shape, int _x, int _y, Color _color);
	~Rat();
};
