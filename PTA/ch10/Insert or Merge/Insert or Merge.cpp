#include<iostream>
using namespace std;

typedef int ElementType;
int isInsertion(ElementType A[], ElementType S[], int N);
void Insertion_pass(ElementType S[], int N, int i);
int GetLength(ElementType S[], int N);
void Merge_pass(ElementType S[], ElementType TmpA[], int N, int l);
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);

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
		cout << "Merge Sort" << endl;
		int l = GetLength(S, N);
		ElementType * TmpA = new ElementType[N];
		Merge_pass(S, TmpA, N, l);
		for (int i = 0; i < N; i++)
		{
			if (flag == 0)
				flag = 1;
			else
				cout << " ";
			cout << S[i] << " ";
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
			cout << S[i] << " ";
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

int GetLength(ElementType S[], int N)
{
	int l,i;
	for (l = 2; l <= N; l *= 2)
	{
		for (i = l - 1; i<N-1; i += 2 * l)
		{
			if (S[i] > S[i + 1])
				return l;
		}
		
	}
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd = R - 1;
	int NumElements = RightEnd - L + 1;
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
void Merge_pass(ElementType S[], ElementType TmpA[],int N, int l)
{
	int i;
	for (i = 0; i <= N - 2 * l; i += 2 * l)
		Merge(S, TmpA, i, i + l, i + 2 * l - 1);
	if (i + l < N)
		Merge(S, TmpA, i, i + l, N - 1);
	else
		for (int j = i; j < N; j++)
			TmpA[j] = S[j];
	for (int i = 0; i < N; i++)
		S[i] = TmpA[i];
}

