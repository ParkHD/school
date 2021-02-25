#include "ObjectFactory.h"
#include "Player.h"
#include "Enemy.h"

ObjectFactory* ObjectFactory::instance = nullptr;

Obj* ObjectFactory::CreateObject(OBJ_TYPE type)
{
	Obj* newObj = nullptr;
	switch (type)
	{
	case PLAYER:
		newObj = new Player;
		break;
	case ENEMY:
		newObj = new Enemy;
		break;
	case NPC:
		break;
	default:
		break;
	}

	if (newObj != nullptr)
	{
		newObj->Initialize();
	}

    return newObj;
}
