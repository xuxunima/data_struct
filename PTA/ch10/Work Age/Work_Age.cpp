#include<iostream>
using namespace std;

typedef int ElementType;

struct Node
{
	ElementType data;
	Node * next;
};

typedef Node Bucket[51];

void Bucket_sort(ElementType A[], int N);
int main()
{
	int N;
	cin >> N;
	ElementType * A = new ElementType[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Bucket_sort(A, N);
	return 0;
}

void Bucket_sort(ElementType A[], int N)
{
	Bucket B;
	for (int i = 0; i < 51; i++)
	{
		B[i].next = nullptr;
	}
	for (int i = 0; i < N; i++)
	{
		Node * tmp = new Node;
		tmp->data = A[i];
		tmp->next = B[A[i]].next;
		B[A[i]].next = tmp;
	}
	int count = 0;
	for (int i = 0; i < 51; i++)
	{
		if (B[i].next != nullptr)
		{
			cout << i << ":";
			Node * T = B[i].next;
			while (T)
			{
				count++;
				T = T->next;
			}
			cout << count << endl;
			count = 0;
		}
	}
}