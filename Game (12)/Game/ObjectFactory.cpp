#include "ObjectFactory.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

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
	case BULLET:
		newObj = new Bullet;
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
