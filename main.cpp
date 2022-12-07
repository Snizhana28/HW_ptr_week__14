#include <iostream>
using namespace std;

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
int* deletePrimesNum(int* arr, int* size)
{
	int size1 = 0;
	for (int i = 0; i < *size; i++)
	{
		for (int j = 1, x = 0; j <= *(arr + i); j++)
		{
			if (*(arr + i) % j == 0)
			{
				x++;
			}
			if (j == *(arr + i) && x > 2)
			{
				size1++;
			}
			else if (j == *(arr + i) && x <= 2)
			{
				*(arr + i) = 0;
			}
		}
	}
	int* arr1 = new int[size1];
	for (int i = 0, j = 0; i < *size; i++)
	{
		if (*(arr + i) != 0)
		{
			*(arr1 + j) = *(arr + i);
			j++;
		}
	}
	*size = size1;
	return arr1;
}
int main()
{
	int size{ 20 };
	int* arr = new int[size] { 2, 4, 3, 6, 5, 10, 7, 16, 11, 26, 41, 34, 43, 58, 47, 65, 53, 15, 59, 60 };
	printArray(arr, size);
	arr = deletePrimesNum(arr, &size);
	printArray(arr, size);
}