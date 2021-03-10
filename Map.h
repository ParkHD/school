#pragma once
#include "Include.h"
class Map
{

public:

	virtual void Render() PURE;
	virtual int CheckMap(int x, int y) PURE;
};

