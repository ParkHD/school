#pragma once
#include "Scene.h"
class Logo : public Scene
{
private:
	const char* logoImage[13];
public:
	//�Լ� �̸�, ��ȯ��, �Ű����� ������ �����Լ�
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};
