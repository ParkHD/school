#pragma once
#include "ObjectFactory.h"
#include "Singleton.h"
class ObjectPoolManager : public Singleton<ObjectPoolManager>
{

public:
	Obj* player;
	Obj* enemy;
	Obj* bullet[BulletCount];
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};

