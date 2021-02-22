#include <iostream>

using namespace std;

class MyClass
{
public:
	int num;
public:
	//생성자
	MyClass() { cout << "생성자" << endl; }
	//MyClass(MyClass& copy) { cout << "복사 생성자" << endl; num = copy.num; }		// 복사생성자는 기본적으로 들어있다

	~MyClass() { cout << "소멸자" << endl; }

private:

};
class MyClass2
{
public:
	int* num;
public:
	//생성자
	MyClass2()
	{ 
		cout << "생성자" << endl; 
	}
	MyClass2(MyClass2& copy) 
	{ 
		cout << "복사 생성자" << endl;
		num = new int;
		*num = *(copy.num);
	}		// 복사생성자는 기본적으로 들어있다

	~MyClass2() { cout << "소멸자" << endl; }

private:

};
int main()
{
	MyClass class1; // 생성자
	class1.num = 10;
	MyClass class2(class1); // 복사 생성자
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