#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

enum STEP
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

enum DIR
{
	LEFT, 
	RIGHT,
	UP,
	DOWN,
};

#define BufferWidth 120
#define BufferHeight 80

const DWORD KEY_UP	    = 0x00000001;
const DWORD KEY_DOWN	= 0x00000002;
const DWORD KEY_LEFT	= 0x00000004;
const DWORD KEY_RIGHT	= 0x00000008;
const DWORD KEY_SPACE	= 0x00000010;
const DWORD KEY_RETURN	= 0x00000020;