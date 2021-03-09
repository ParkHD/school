#pragma once
#include <array>
#include "Include.h"
class Map
{
public:
	array<array<int, 50>, 50> map;
public:
	virtual void Initialize() PURE;
	virtual void Progress() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

