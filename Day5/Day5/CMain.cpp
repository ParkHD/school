#include<iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "����" << endl;
	}
	Animal(int age)
	{
		cout << age << "�� ���� ����" << endl;
	}
	//~Animal()
	//{
	//	cout << "����" << endl;
	//}
};
class Cat : public Animal
{
public:
	static int age;
public:

	Cat()
	{
		cout << age << "cat ����" << endl;
	}
	Cat(int _age)
	{
		cout <<_age << "�� cat ����" << endl;
	}

	//~Cat()
	//{
	//	cout << "cat die" << endl;
	//}
};
class Dog : public Animal
{
public:
	Dog()
	{
		cout << "dog live" << endl;
	}
	//~Dog()
	//{
	//	cout << "dog die" << endl;
	//}
};
class Cat2
{
public:
	static Cat2* cat;

};
int Cat::age = 0;

int main()
{
	Animal animal;

	Dog dog;
	Cat cat;

	cout << "=====================" << endl;
	Animal* animal2 = new Cat;

	cout << "=====================" << endl;
	Cat cat2(12);										// �ڽ��� �����ڴ� �θ��� defalt�����ڸ� ȣ���ϰ� �ڽ��� �����ڸ� ȣ����


	//int Cat::age = 0;									// �ʱ�ȭ�� ���⼭ �ȴ��
	cat.age = 10;
	cat2.age = 20;
	cout << cat.age << endl;
	cout << cat2.age << endl;
	cout << "=====================" << endl;
	
	
}