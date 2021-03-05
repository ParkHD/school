#pragma once
#include "Singleton.h"
class GameData : public Singleton<GameData>
{
public:
	int killMark;
public:
	GameData() { killMark = 0; }
};

