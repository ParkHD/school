//#include<iostream>
//
//using namespace std;
//
//class Cat
//{
//public:
//	int m_age;
//
//	Cat()
//	{}
//	Cat(int age)
//	{
//		m_age = age;
//	}
//	~Cat();
//};
//Cat::~Cat()
//{
//	cout << "소멸" << endl;
//}
//
//Cat cat;										// 메인 함수 밖 생성 -> 데이터영역
//Cat cat(12);									// 프로그램 종료시 없어짐 // 단점 : 생성되면 프로그램 종료시까지 남아있어서 메모리 차지
//
//int main()
//{
//	cout << " Hello, World " << endl;
//
//	Cat* cat1 = new Cat;
//
//	return 0;
//}