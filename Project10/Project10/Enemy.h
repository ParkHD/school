#pragma once
#include "Object.h"
class Enemy :
    public Object
{
private:
    const char* e_shape[2];
private:
    float t;
    int h;
    float v0;
    float G = 9.8f;

    bool isGrounded;
public:
    virtual void Initialize();
    virtual void Progress();
    virtual void Render();
    virtual void Release();
public:
    int getRandomDir();
};

