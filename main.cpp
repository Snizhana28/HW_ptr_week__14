#include <iostream>
#include <time.h>
using namespace std;

void initArray(int* arr, int size)
{
	arr = new int[size];
}

void randArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 80 + 1;
	}
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void deleteArray(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}

void push_back(int*& arr, int& size, int value)
{
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	deleteArray(arr);
	arr = newArray;
}

int main()
{
	srand(time(0));
	int size;
	cout << "Enter an array size from 5 to 20: ";
	cin >> size;
	int* arr = new int[size];

	initArray(arr, size);
	randArray(arr, size);
	printArray(arr, size);
	push_back(arr, size, 22);
	printArray(arr, size);
	return 0;
}