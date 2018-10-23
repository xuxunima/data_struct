#include<iostream>
using namespace std;

typedef int ElementType;

void Insertion_Sort(ElementType A[], int N);

int main()
{
	const int N = 5;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Insertion_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Insertion_Sort(ElementType A[], int N)
{
	int p, i;
	ElementType Temp;
	for (p = 1; p < N; p++)
	{
		Temp = A[p];
		for (i = p; i > 0 && A[i - 1] > Temp; i--)
			A[i] = A[i - 1];
		A[i] = Temp;
	}
}