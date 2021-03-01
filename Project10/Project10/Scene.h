#pragma once
#include<Windows.h>
class Scene
{
public:
	virtual void Initialize() PURE;
	virtual void Progress() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

