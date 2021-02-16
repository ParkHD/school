#pragma once
#include<iostream>
#include"Skeleton.h"
#include<string>
class Monster
{
public :
	int health = 100;
	int damage = 10;

public : 
	void print()
	{
		std::cout << health << " " << damage << " " << "ÅÂ¾î³µ´Ù" << std::endl;
	}
};

