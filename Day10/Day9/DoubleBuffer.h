#pragma once
#include "Include.h"

class DoubleBuffer
{
private:
	static DoubleBuffer* instance;
public:
	static DoubleBuffer* Instance()
	{
		if (instance == nullptr)
		{
			instance = new DoubleBuffer;
		}

		return instance;
	}
private:
	HANDLE hBuffer[2];// 창 두개
	int screenIndex; // 0 or 1
public:
	//버퍼 초기화
	void InitBuffer();
	//버퍼를 바꿔줌 0->1 / 1->0
	void FlipBuffer();
	//화면 지우기
	void ClearBuffer();
	//화면에 써주기
	void WriteBuffer(int x, int y, const char* shape, int color);
	//버퍼 해제
	void DestroyBuffer();
};