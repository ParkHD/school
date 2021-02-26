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

enum  OBJ_TYPE
{
	PLAYER,
	ENEMY,
	NPC,
	BULLET,
};
enum Dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

#define BufferWidth 102
#define BufferHeight 52

#define BulletCount 10