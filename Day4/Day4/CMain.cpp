//#include <iostream>
//#include "LandPlants.h"
//#include "Birds.h"
//using namespace std;
//
//class Parent
//{
//public:
//	virtual void Print() { cout << "Parent" << endl; }
//};
//
//class Child : public Parent
//{
//public:
//	void Print() { cout << "Child" << endl; }
//};
//
//int main()
//{
//	Parent* parent = new Parent;
//	parent->Print();
//
//	Child* child= new Child;
//	child->Print();
//
//
//
//	LandPlants plants;
//	plants.age = 10;
//	plants.Print();
//	Protists pro;
//	pro.age = 20;
//	pro.Print();
//
//
//
//	return 0;
//}
#include <iostream>
#include "Monster.h"
using namespace std;

class Parent
{
public:
	virtual void Print() { cout << "Parent" << endl; }
};

class Child : public Parent
{
public:
	void Print() { cout << "Child" << endl; }
};
class Child2 : public Parent
{
public:
	//void Print() { cout << "Child2" << endl; }
};

int main()
{
	Parent* newChild = new Child();
	newChild->Print();

	Parent* newChild2 = new Child2();
	newChild2->Print();

	Skeleton ske;
	ske.print();


	string name;

	return 0; 
}