#include <iostream>

using namespace std;

class MyClass
{
public:
	int num;
public:
	//������
	MyClass() { cout << "������" << endl; }
	//MyClass(MyClass& copy) { cout << "���� ������" << endl; num = copy.num; }		// ��������ڴ� �⺻������ ����ִ�

	~MyClass() { cout << "�Ҹ���" << endl; }

private:

};
class MyClass2
{
public:
	int* num;
public:
	//������
	MyClass2()
	{ 
		cout << "������" << endl; 
	}
	MyClass2(MyClass2& copy) 
	{ 
		cout << "���� ������" << endl;
		num = new int;
		*num = *(copy.num);
	}		// ��������ڴ� �⺻������ ����ִ�

	~MyClass2() { cout << "�Ҹ���" << endl; }

private:

};
int main()
{
	MyClass class1; // ������
	class1.num = 10;
	MyClass class2(class1); // ���� ������
	//MyClass class2 = class1;
	cout << class2.num << endl;

	MyClass2 class11;
	class11.num = new int;
	*(class11.num) = 10;
	MyClass2 class22(class11);
	*(class11.num) = 20;
	cout << *(class11.num) << endl;
	cout << *(class22.num) << endl;
}