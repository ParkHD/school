#include "Human.h"
#include<iostream>
using namespace std;

Human::Human()							// 메모리가 할당됬을 때 실행
{
	name = "AMuGe";
	age = 0;
	cout << " constructor" << endl;
}
Human::~Human()
{
	cout << " deconstruct " << endl;
}
void Human::print()
{
	cout << name << " " << age << endl;
}