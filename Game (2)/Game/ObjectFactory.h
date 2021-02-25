#pragma once
#include "Obj.h"
class ObjectFactory
{
private:
	static ObjectFactory* instance;
public:
	static ObjectFactory* Instance()
	{
		if (instance == nullptr)
		{
			instance = new ObjectFactory;
		}

		return instance;
	}
public:
	Obj* CreateObject(OBJ_TYPE type);
};

