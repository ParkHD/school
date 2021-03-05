#pragma once
#include "Singleton.h"

class KeyManager : public Singleton<KeyManager>
{
private:
	DWORD dwKey;
public:
	DWORD GetKey() { return dwKey; }
public:
	void CheckKey();
};

