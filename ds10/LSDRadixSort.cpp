#include<iostream>
using namespace std;

typedef int ElementType;
const int MaxDigits = 4;
const int Radix = 10;

struct Node
{
	int key;
	Node * next;
};
typedef Node * PtrToNode;

struct HeadNode
{
	PtrToNode head, tail;
};
typedef HeadNode Bucket[Radix];

int GetDigit(int X, int D);
void LSDRadixSort(ElementType A[], int N);

int main()
{
	const int N = 300;
	ElementType A[N];
	for (int i = 0; i < N; i++)
		A[i] = N - i;
	LSDRadixSort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}

int GetDigit(int X, int D)
{
	int i;
	int p;
	for (i = 1; i <= D; i++)
	{
		p = X % Radix;
		X = X / Radix;
	}
	return p;
}

void LSDRadixSort(ElementType A[], int N)
{
	Bucket B;
	int D,Di;
	PtrToNode tmp, p, List = nullptr;
	for (int i = 0; i < Radix; i++)
	{
		B[i].head = B[i].tail = nullptr;
	}

	for (int i = 0; i < N; i++)
	{
		tmp = new Node;
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}

	for (int D = 1; D <= MaxDigits; D++)
	{
		p = List;
		while (p)
		{
			Di = GetDigit(p->key, D);
			tmp = p;
			p = p->next;
			tmp->next = nullptr;
			if (B[Di].head == nullptr)
			{
				B[Di].head = B[Di].tail = tmp;
			}
			else
			{
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}

		List = nullptr;
		for (int D = Radix - 1; D >= 0; D--)
		{
			if (B[D].head)
			{
				B[D].tail->next = List;
				List = B[D].head;
				B[D].head = B[D].tail = nullptr;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		delete tmp;
	}
}