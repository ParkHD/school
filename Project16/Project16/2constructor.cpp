#include<iostream>
#include"Human.h"

using namespace std;

class People
{
public:
	const char* name;
	int			age;

	People()							// �޸𸮰� �Ҵ���� �� ����
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
	People jack;						// ������ ȣ��
	People* people = new People;
	
	jack.print();
	jack.name = "jack";
	jack.age = 15;
	jack.print();

	cout << "now" << endl;

	Human human;
	human.print();


	delete people;						// �Ҹ��� ȣ��(�����Ҵ�)
	return 0;							// �Ҹ��� ȣ��


}