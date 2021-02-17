#include<iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "생성" << endl;
	}
	Animal(int age)
	{
		cout << age << "살 동물 생성" << endl;
	}
	//~Animal()
	//{
	//	cout << "삭제" << endl;
	//}
};
class Cat : public Animal
{
public:
	static int age;
public:

	Cat()
	{
		cout << age << "cat 생성" << endl;
	}
	Cat(int _age)
	{
		cout <<_age << "살 cat 생성" << endl;
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
	Cat cat2(12);										// 자식의 생성자는 부모의 defalt생성자를 호출하고 자식의 생성자를 호출함


	//int Cat::age = 0;									// 초기화는 여기서 안댄당
	cat.age = 10;
	cat2.age = 20;
	cout << cat.age << endl;
	cout << cat2.age << endl;
	cout << "=====================" << endl;
	
	
}