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
	HANDLE hBuffer[2];// â �ΰ�
	int screenIndex; // 0 or 1
public:
	//���� �ʱ�ȭ
	void InitBuffer();
	//���۸� �ٲ��� 0->1 / 1->0
	void FlipBuffer();
	//ȭ�� �����
	void ClearBuffer();
	//ȭ�鿡 ���ֱ�
	void WriteBuffer(int x, int y, const char* shape, int color);
	//���� ����
	void DestroyBuffer();
};