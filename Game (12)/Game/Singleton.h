#pragma once
#include "Include.h"

template<typename T>
class Singleton
{
private:
	static T* instance;
public:
	static T* Instance()
	{
		if (instance == nullptr)
		{
			instance = new T;
		}

		return instance;
	}
};

template<typename T>T* Singleton<T>::instance = nullptr;
