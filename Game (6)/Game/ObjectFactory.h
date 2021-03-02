#pragma once
#include "Obj.h"
#include "Singleton.h"
class ObjectFactory : public Singleton<ObjectFactory>
{

public:
	Obj* CreateObject(OBJ_TYPE type);
};

