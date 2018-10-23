#include<iostream>
using namespace std;

typedef int ElementType;

void Bubble_Sort(ElementType A[], int N);
void Swap(ElementType *a, ElementType *b);

int main()
{
	const int N = 5;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Bubble_Sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

void Bubble_Sort(ElementType A[], int N)
{
	int p, i;
	for (p = N - 1; p >= 0; p--)
	{
		int flag = 0;
		for (i = 0; i < p; i++)
		{
			if (A[i] > A[i + 1])
			{
				Swap(A+i, A+i+1);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType Temp;
	Temp = *a;
	*a = *b;
	*b = Temp;
}