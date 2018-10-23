#include<iostream>
using namespace std;

typedef int ElementType;

void PerDown(ElementType A[], int p, int N);
void Swap(ElementType * a, ElementType* b);
void HeapSort(ElementType A[], int N);

int main()
{
	const int N = 10;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	HeapSort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i];
	return 0;
}

void PerDown(ElementType A[], int p, int N)
{
	int parent, child;
	ElementType x = A[p];
	for (parent = p; (parent * 2 + 1) < N; parent = child)
	{
		child = parent * 2 + 1;
		if (child != N - 1 && A[child] < A[child + 1])
			child++;
		if (x>= A[child])
			break;
		else
			A[parent] = A[child];
	}
	A[parent] = x;
}

void Swap(ElementType * a, ElementType* b)
{
	ElementType t;
	t = *a;
	*a = *b;
	*b = t;
}

void HeapSort(ElementType A[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		PerDown(A, i, N);
	for (int i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);
		PerDown(A, 0, i);
	}
}
