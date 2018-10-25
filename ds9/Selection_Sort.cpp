#include<iostream>
using namespace std;

typedef int ElementType;
void Selection_Sort(ElementType A[], int N);
int FindMinP(ElementType A[], int p, int N);
void Swap(ElementType * a, ElementType *b);

int main()
{
	const int N = 10;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Selection_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

int FindMinP(ElementType A[], int p, int N)
{
	int MinP;
	ElementType MinEle = 63353;
	for (int i = p; i <= N; i++)
	{
		if (A[i] < MinEle)
		{
			MinEle = A[i];
			MinP = i;
		}
	}
	return MinP;
}

void Swap(ElementType * a, ElementType *b)
{
	ElementType t;
	t = *a;
	*a = *b;
	*b = t;
}
void Selection_Sort(ElementType A[], int N)
{
	int MinP;
	for (int i = 0; i < N; i++)
	{
		MinP = FindMinP(A, i, N - 1);
		Swap(&A[i], &A[MinP]);
	}
}