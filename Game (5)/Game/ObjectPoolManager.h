#pragma once
#include "ObjectFactory.h"
class ObjectPoolManager
{
private:
	static ObjectPoolManager* instance;
public :
	static ObjectPoolManager* Instance()
	{
		if (instance == nullptr)
		{
			instance = new ObjectPoolManager;
		}

		return instance;
	}
public:
	Obj* player;
	Obj* enemy;
	Obj* bullet[BulletCount];
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
	void Release(Obj* bullet);
};

