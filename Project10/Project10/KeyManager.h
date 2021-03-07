#pragma once
#include "Include.h"
class KeyManager 
{
private:
	static KeyManager* instance;
public:
	static KeyManager* Instance()
	{
		if (instance == nullptr)
			instance = new KeyManager;
		return instance;
	}
private:
	DWORD dwKey;
public:
	DWORD GetKey() { return dwKey; }
public:
	void CheckKey();
};

