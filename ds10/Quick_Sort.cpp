#include<iostream>
#include<stack>
using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Median3(int A[], int left, int right)
{
	int center = (left + right) / 2;
	if (A[left] > A[center])
		swap(&A[left], &A[center]);
	if (A[left] > A[right])
		swap(&A[left], &A[right]);
	if (A[center] > A[right])
		swap(&A[center], &A[right]);
	swap(&A[center], &A[right]);
	return A[right];
}

int partition(int A[], int start, int end)
{

	int p = Median3(A, start, end);

	int i = start;
	int j = end - 1;
	while (i < j)
	{
		while (A[i] < p)
			i++;
		while (A[j] > p)
			j--;
		if (i < j)
			swap(&A[i++], &A[j--]);
	}
	swap(&A[i], &A[end]);
	return i;
}

void quicksort(int A[], int left, int right)
{
	if (left > right)
		return;
	int  p = partition(A, left, right);
	quicksort(A, left, p - 1);
	quicksort(A, p + 1, right);
}

int main()
{
	int A[] = { 2,6,4,7,8,9,1,5 };
	quicksort(A, 0, 7);
	for (int i = 0; i < 8; i++)
		cout << A[i];
	cout << endl;
	return 0;
}