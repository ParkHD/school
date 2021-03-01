#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    virtual void Initialize();
    virtual void Progress();
    virtual void Render();
    virtual void Release();
};

