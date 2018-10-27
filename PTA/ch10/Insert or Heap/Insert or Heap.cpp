#include<iostream>
using namespace std;

typedef int ElementType;
int isInsertion(ElementType A[], ElementType S[], int N);
void Insertion_pass(ElementType S[], int N, int i);
void Heap_Sort(ElementType S[], int N);
int GetLength(ElementType S[], int N);
void Swap(ElementType *a, ElementType *b);
void PercDown(ElementType A[], int p, int N);

int main()
{
	int N;
	cin >> N;
	int flag = 0;
	ElementType * A = new ElementType[N];
	ElementType * S = new ElementType[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> S[i];

	int a = isInsertion(A, S, N);
	if (a == -1)
	{
		cout << "Heap Sort" << endl;
		int l = GetLength(S, N);
		Heap_Sort(S, N);
		for (int i = 0; i < N; i++)
		{
			if (flag == 0)
				flag = 1;
			else
				cout << " ";
			cout << S[i];
		}
			
	}
		
	else
	{
		cout << "Insertion Sort" << endl;
		Insertion_pass(S, N, a);
		for (int i = 0; i < N; i++)
		{
			if (flag == 0)
				flag = 1;
			else
				cout << " ";
			cout << S[i];
		}
	}
		
	return 0;
}

int isInsertion(ElementType A[], ElementType S[], int N)
{
	int i, p;
	for (i = 1; i<N && S[i - 1] <= S[i]; i++);
	p = i;
	for (i; i<N; i++)
	{
		if (A[i] != S[i])
			break;
	}
	if (i == N)
		return p;
	else
		return -1;

}

void Insertion_pass(ElementType S[], int N, int i)
{
	ElementType tmp = S[i];
	int j;
	for (j = i; j>0 && tmp<S[j - 1]; j--)
	{
		S[j] = S[j - 1];
	}
	S[j] = tmp;
}

void PercDown(ElementType A[], int p, int N)
{
	int parent, child;
	ElementType tmp = A[p];
	for (parent = p; (parent * 2 + 1) < N; parent = child)
	{
		child = parent * 2 + 1;
		if (child != N - 1 && A[child] < A[child + 1])
			child++;
		if (tmp >= A[child])
			break;
		else
			A[parent] = A[child];
	}
	A[parent] = tmp;
}

void Swap(ElementType *a, ElementType *b)
{
	ElementType t;
	t = *a;
	*a = *b;
	*b = t;
}

int GetLength(ElementType S[], int N)
{
	int i;
	for (i = N - 1; i >= 0; i--)
	{
		if (S[i] < S[0])
			break;
	}
	return i;
}

void Heap_Sort(ElementType S[], int N)
{
	int End = GetLength(S, N);
	Swap(&S[0], &S[End]);
	PercDown(S, 0, End);
}

