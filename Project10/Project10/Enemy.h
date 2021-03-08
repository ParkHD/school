#pragma once
#include "Object.h"
#include <vector>
class Enemy :
    public Object
{
private:
    int size;
    vector<string> arr;
    const char* e_shape[3];
private:
    float t;
    int h;
    float v0;
    float G = 9.8f;

    bool isGrounded;

    int step;
    int maxStep;
    int dir;

    int timeStep;
    bool bubble;
public:
    virtual void Initialize();
    virtual void Progress();
    virtual void Render();
    virtual void Release();
public:
    int getRandomDir();
    DIR GetRandomDirection();
};

