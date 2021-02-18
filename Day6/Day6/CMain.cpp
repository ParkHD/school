#include<iostream>

using namespace std;

int main()
{
	using namespace std;  

	int row;
	cin >> row;
	int** array = new int*[row];

	int column;
	cin >> column;
	for (int i = 0; i < row; i++)
	{
		array[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			array[i][j] = i;
		}
	}


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << array[i][j] << " " << i << j << endl;
		}
	}
	return 0;
}