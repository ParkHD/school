#pragma once
#include "Scene.h"
class Logo : public Scene
{
private:
	const char* logoImage[13];
public:
	//함수 이름, 반환형, 매개변수 같으면 가상함수
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
};
