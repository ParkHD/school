#include "Human.h"
#include<iostream>
using namespace std;

Human::Human()							// �޸𸮰� �Ҵ���� �� ����
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