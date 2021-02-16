#pragma once
#include "Seaweed.h"
class LandPlants :
    public Seaweed
{
public:

    void Print()
    {
        std::cout << "Protophytes " << age << std::endl;
    }
};

