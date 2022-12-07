#include <iostream>
using namespace std;
void initArray(int* arr, int size)
{
	for (int i = 0;i < size;i++)
	{
		cin >> *(arr + i);
	}
	cout << "\n\n";
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
void result(int* a, int size)
{
	cout << "\n";
	for (int i = 0; i < size; a++, i++)
		if (*a > 0) cout << *a << " ";
	cout << endl;
}
int main()
{
	const int size_a = 5;
	int A[size_a];
	int* ptr_a;
	ptr_a = &A[0];

	const int size_b = 5;
	int B[size_b];
	int* ptr_b;
	ptr_b = &A[0];

	const int size_c = size_a + size_b;
	int C[size_c];
	int* ptr_c;
	ptr_c = &C[0];
	int tmp = 0;

	cout << "Enter elements in arr1 (size = 5) \n";
	initArray(A, size_a);
	cout << "Enter elements in arr2 (size = 5) \n";

	initArray(B, size_b);
	printArray(A, size_a);
	printArray(B, size_b);

	ptr_c = C;
	tmp = 0;
	for (ptr_a = A; ptr_a < A + size_a; ptr_a++)
	{
		for (ptr_b = B; ptr_b < B + size_b; ptr_b++)
		{
			if (*ptr_a == *ptr_b)
				tmp++;
		}
		if (tmp == 0) {
			*ptr_c = *ptr_a;
			ptr_c++;
		}
		tmp = 0;
	}
	cout << "Result" << endl;
	result(C, size_c);
	return 0;
}