#pragma once
#include "Obj.h"


class Enemy :
    public Obj
{
public:
    Dir dir;
    int step;
    int maxStep;
public:
    void Initialize();
    void Progress();
    void Render();
    void Release();
private:
    Dir GetRandomDir();
    bool Collider();
};

