#pragma once
#include "Monster.h"
class Animal :
    public Monster
{
public:
    std::string name;
public:
    Animal()
    {
        damage = 120;
        health = 300;
    }

    void Attack()
    {

    }
};

