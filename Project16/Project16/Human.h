#pragma once
#include<iostream>

using namespace std;

class Human
{
public:
	const char* name;
	int			age;

	Human();							// 메모리가 할당됬을 때 실행
	
	~Human();
	
	void print();
	
	
};

