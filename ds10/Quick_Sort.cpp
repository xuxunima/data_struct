#include<iostream>
using namespace std;

typedef int ElementType;
const int Cutoff = 100;

void Inserttion_Sort(ElementType A[], int N);
void Swap(ElementType *a, ElementType *b);
ElementType Median3(ElementType A[], int Left, int Right);
void Quicksort(ElementType A[], int Left, int Right);
void Quick_Sort(ElementType A[], int N);

int main()
{
	int N = 200;
	ElementType A[200];
	for (int i = 0; i < N; i++)
		A[i] = 200 - i;
	Quick_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType t;
	t = *a;
	*a = *b;
	*b = t;
}

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void Quicksort(ElementType A[], int Left, int Right)
{
	if (Cutoff < Right - Left)
	{
		ElementType Pivot;
		Pivot = Median3(A, Left, Right);
		int i = Left;
		int j = Right - 1;
		for (;;)
		{
			while (A[++i] < Pivot) {};
			while (A[--j] > Pivot) {};
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);
		Quicksort(A, Left, i - 1);
		Quicksort(A, i + 1, Right);
	}
	else
	{
		Inserttion_Sort(A + Left, Right - Left + 1);
	}
	
}

void Inserttion_Sort(ElementType A[], int N)
{
	int p,i;
	ElementType Tmp;
	for (p = 1; p < N; p++)
	{
		Tmp = A[p];
		for (i = p; i > 0 && A[i-1] > Tmp; i--)
		{
			A[i] = A[i - 1];
		}
		A[i] = Tmp;
	}
}

void Quick_Sort(ElementType A[], int N)
{
	Quicksort(A, 0, N - 1);
}