#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    const char* p_shape[2];

    float t;
    int h;
    float v0;
    float G = 9.8f;


    bool jump;
    bool isGrounded;
    bool isJump;

    int BulletCount = 5;

    int health;
    const char* h_shape;

    int count;

    const char* test;

    bool stun;
public:
    virtual void Initialize();
    virtual void Progress();
    virtual void Render();
    virtual void Release();

    void Jump();
    void Gravity();
};

