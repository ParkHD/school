#pragma once
#include "Map.h"
class Stage1 : public Map
{
public:
    virtual void Initialize();
    virtual void Progress();
    virtual void Render();
    virtual void Release();
};

