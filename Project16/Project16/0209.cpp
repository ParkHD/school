//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//struct Human
//{
//	int		age;		 // 4byte		
//	float	weight;		 // 4byte
//	float	height;		
//	const char*	name;
//
//	void Eat()
//	{
//		int x;
//		cout << name << " " << "eat" << endl;
//	}
//	void Poop()
//	{
//		cout << "Poo" << endl;
//	}
//	void Sleep()
//	{
//		cout << "sleep" << endl;
//	}
//};
//
//int main()
//{
//	cout << "Hello world" << endl;
//
//	char word[20];											// 1byte*20 = 20byte
//	cout << sizeof(word) << "byte" << endl;
//	cin.getline(word, 30);									// input space
//	cout << word << endl;
//	cout << sizeof(word) << "byte" << endl;					// 1byte*20 = 20byte
//
//	Human human;
//	human.name = "jack sparow";
//
//	Human human2;
//	human2.name = "same";
//
//	cout << sizeof(human) << "byte" << endl;				// 12byte(function은 용량에 no)
//	human.Eat();
//	human2.Eat();
//	
//	
//	int size;
//	cout << " size :";
//	cin >> size;
//	char* name = new char[size];
//	cin >> name;
//	cout << name << endl;
//
//
//
//
//	delete[] name;
//
//
//	return 0;
//}