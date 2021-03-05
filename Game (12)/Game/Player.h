#pragma once
#include "Obj.h"

class Player : public Obj
{
public:
	bool aact = true;


	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

	virtual int collision(DIR dir);
};

