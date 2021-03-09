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
	검정색,
	파란색,
	초록색,
	옥색,
	빨간색,
	자주색,
	노란색,
	흰색,
	회색,
	밝은파란색,
	밝은초록색,
	밝은옥색,
	밝은빨간색,
	밝은자주색,
	밝은노란색,

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