#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

enum SCENE_ID
{
	LOGO,
	MENU,
	STAGE,
};

enum Color
{
	������,
	�Ķ���,
	�ʷϻ�,
	����,
	������,
	���ֻ�,
	�����,
	���,
	ȸ��,
	�����Ķ���,
	�����ʷϻ�,
	��������,
	����������,
	�������ֻ�,
	���������,

};
enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
};
enum  OBJ_TYPE
{
	PLAYER,
	ENEMY,
	NPC,
};

#define BufferWidth 120
#define BufferHeight 60