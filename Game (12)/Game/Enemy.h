#pragma once
#include "Obj.h"
class Enemy : public Obj
{
private:
	int timeStep;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
private:
	DIR GetRandomDirection();
	void CheckCollision();
	bool CheckLeftCollision();
	bool CheckRightCollision();
	bool CheckTopCollision();
	bool CheckBottomCollision();
	void SetReposition();
};


