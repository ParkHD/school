#pragma once
#include "DoubleBuffer.h"
#include "Include.h"
class Obj
{
public:
	Info info;

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render() 
	{

		if (info.act)
		{
			DoubleBuffer::Instance()->WriteBuffer(info.x, info.y, info.shape, info.color);
		}
	}
	virtual void Release()PURE;
};