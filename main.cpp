#include <iostream>
using namespace std;
void printArray(int* arr, int const* size);
int* resultArray(int* arr, int const* size);

int main()
{
	int const size = 20;
	int arr[size]{ -2, 4, 3, -6, 5, 0, 7, 0, 11, 26, 0, 34, -43, 58, -47, 65, -53, 0, 59, 0 };
	printArray(arr, &size);
	resultArray(arr, &size);
}
void printArray(int* arr, int const* size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
int* resultArray(int* arr, int const* size)
{
	int sizeNull = 0;
	int sizePlus = 0;
	int sizeMinus = 0;
	for (int i = 0; i < *size; i++)
	{
		if (*(arr + i) > 0)
		{
			sizePlus++;
		}
		else if (*(arr + i) < 0)
		{
			sizeMinus++;
		}
		else
		{
			sizeNull++;
		}
	}
	int* arrPlus = new int[sizePlus];
	int* arrMinus = new int[sizeMinus];
	int* arrNull = new int[sizeNull];
	for (int i = 0, j = 0, n = 0, k = 0; i < *size; i++)
	{
		if (*(arr + i) > 0)
		{
			*(arrPlus + j) = *(arr + i);
			j++;

		}
		else if (*(arr + i) < 0)
		{
			*(arrMinus + n) = *(arr + i);
			n++;
		}
		else
		{
			*(arrNull + k) = *(arr + i);
			k++;
		}
	}
	cout << "\nNumber (+) " << endl;
	printArray(arrPlus, &sizePlus);
	cout << "\nNumber (-) " << endl;
	printArray(arrMinus, &sizeMinus);
	cout << "\nNumber (0) " << endl;
	printArray(arrNull, &sizeNull);
	return 0;
}