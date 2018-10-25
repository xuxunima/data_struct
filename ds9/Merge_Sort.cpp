#include<iostream>
using namespace std;

typedef int ElementType;

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
void M_Sort(ElementType A[], ElementType TmpA[], int L, int RightEnd);
void Merge_Sort(ElementType A[], int N);

int main()
{
	const int N = 10;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Merge_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd = R - 1;
	int NumElement = RightEnd - L + 1;
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
	for (int i = 0; i < NumElement; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}

void M_Sort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;
	if (L < RightEnd)
	{
		Center = (L + RightEnd) / 2;
		M_Sort(A, TmpA, L, Center);
		M_Sort(A, TmpA, Center + 1, RightEnd);
		Merge(A, TmpA, L, Center + 1, RightEnd);
	}
}

void Merge_Sort(ElementType A[], int N)
{
	ElementType * TmpA = new ElementType[N];
	M_Sort(A, TmpA, 0, N - 1);
	delete TmpA;
}