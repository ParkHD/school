#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

#include "Enum.h"
#include "Define.h"

typedef struct Information
{
	bool act;
	int x;
	int y;
	Color color;
	const char* shape[ObjHeight];


}Info;