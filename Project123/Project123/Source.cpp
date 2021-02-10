#include<iostream>
#include<windows.h>
using namespace std;

//class Human
//{
//private:
//	int m_size;
//public:
//	int age = 0;
//	Human()
//	{
//	
//	}
//	Human(const int size)
//	{
//		m_size = size;
//	}
//	~Human()
//	{
//		cout << "Death" << endl;
//	}
//	void setSize(const int& size)
//	{
//		m_size = size;
//	}
//	void print()
//	{
//		cout << m_size << endl;
//	}
//};

class Food
{
public:
	string f_name = "";
	Food()
	{}
	Food(string _name)
	{
		f_name = _name;
	}

};
class Animal
{
public:
	string m_name;
	int m_age;
	Animal(const string name)
	{
		m_name = name;
		m_age = 1;
	}
	~Animal()
	{
		cout << m_name << " death" << endl;
	}
	void eat()
	{
		cout << m_name << " eat" << endl;
	}
	void discover(Food* food)
	{
		cout << m_name << " discover" << food->f_name << endl;
	}
};


int main()
{

	Animal* cat1 = new Animal("YaOng2");
	Animal* dog1 = new Animal("GangAG");

	Food food("banana");

	int year = 0;
	while (year < 14)
	{

		if (dog1 == nullptr)
		{
			dog1->m_age = year;
			cout << dog1->m_name << "나이 :" << dog1->m_age << endl;
		}
		if (cat1 != nullptr)
		{
			cat1->m_age = year;
			cout << cat1->m_name << "나이 :" << cat1->m_age << endl;
		}
		switch (year)
		{
		case 4:
			cat1->discover(&food);
			dog1->eat();
			delete dog1;
			dog1 = nullptr;
			break;
		case 10:
			cout << "-----stack 멸망-----" << endl;
			delete cat1;
			cat1 = nullptr;
			break;
		}

		cout << "===============================" << endl;
		year++;
	}





	//Human human;
	//human.setSize(5);
	//human.print();
	//Human human2(10);
	//human2.print();

	//Human* human3 = new Human(10);

	//while (human3->age < 100)						// 동적할당은 ->?
	//{

	//	human3->age++;
	//	cout << human3->age << endl;
	//	Sleep(100);
	//}
	//delete human3;







	return 0;
}