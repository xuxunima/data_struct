#include<iostream>
using namespace std;

typedef int ElementType;
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length);
void Merge_sort(ElementType A[], int N);

int main()
{
	const int N = 10;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Merge_sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd = R - 1;
	int NumElemet = RightEnd - L + 1;
	int tmp = L;
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[tmp++] = A[L++];
		else
			TmpA[tmp++] = A[R++];
	}
	while (L <= LeftEnd)
		TmpA[tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[tmp++] = A[R++];
}

void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i;
	for (i = 0; i <= N - 2 * length; i += 2 * length)
	{
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	}
	if (i + length < N)
		Merge(A, TmpA, i, i + length, N - 1);
	else
	{
		for (int j = i; j < N; j++)
			TmpA[j] = A[j];
	}
}

void Merge_sort(ElementType A[], int N)
{
	int length = 1;
	ElementType * TmpA = new ElementType[N];
	while (length < N)
	{
		Merge_pass(A, TmpA, N, length);
		length *= 2;
		Merge_pass(TmpA, A, N, length);
		length *= 2;
	}
	delete TmpA;
}