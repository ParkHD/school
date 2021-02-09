#include<iostream>
#include"Human.h"

using namespace std;

class People
{
public:
	const char* name;
	int			age;

	People()							// 메모리가 할당됬을 때 실행
	{
		name = "AMuGe";
		age = 0;
		cout << " constructor" << endl;
	}
	~People()
	{
		cout << " deconstruct " << endl;
	}
	void print()
	{
		cout << name << " " << age << endl;
	}
};

int main()
{
	People jack;						// 생성자 호출
	People* people = new People;
	
	jack.print();
	jack.name = "jack";
	jack.age = 15;
	jack.print();

	cout << "now" << endl;

	Human human;
	human.print();


	delete people;						// 소멸자 호출(동적할당)
	return 0;							// 소멸자 호출


}