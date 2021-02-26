#pragma once
#include "Obj.h"
class Enemy : public Obj
{
public:
	Dir dir;
	int step;
	int maxStep;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
private:
	Dir GetRandomDir();
	bool Collider();
};


