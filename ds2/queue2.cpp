#include<iostream>
using namespace std;

typedef int ElementType;

struct Node
{
	ElementType data;
	Node * Next;
};

struct SNode
{
	Node * front;
	Node * rear;
};

typedef SNode * Queue;

void ShowQ(Queue Q);
Queue CreateQ();
bool isEmpty(Queue Q);
void AddQ(Queue Q, ElementType x);
ElementType DeleteQ(Queue Q);
int main()
{
	Queue Q = CreateQ();
	cout << isEmpty(Q) << endl;
	AddQ(Q, 1);
	AddQ(Q, 2);
	AddQ(Q, 3);
	ShowQ(Q);
	DeleteQ(Q);
	ShowQ(Q);
	return 0;
}

Queue CreateQ()
{
	Queue Q = new SNode;
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));
	Q->front->Next = nullptr;
	return Q;
}

bool isEmpty(Queue Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

void AddQ(Queue Q, ElementType x)
{
	Node * P = new Node;
	P->data = x;
	P->Next = nullptr;
	Q->rear->Next = P;
	Q->rear = P;
}

ElementType DeleteQ(Queue Q)
{
	if (Q->front == Q->rear)
	{
		cout << "the queue is empy" << endl;
		return -1;
	}
	Node * P = Q->front->Next;
	ElementType x = P->data;
	Q->front->Next = P->Next;
	if (Q->rear == P)
		Q->rear = Q->front;
	delete P;
	
}

void ShowQ(Queue Q)
{
	Node * P = new Node;
	P = Q->front->Next;
	while (P != Q->rear)
	{
		cout << P->data << " ";
		P = P->Next;
	}
	cout << P->data << endl;
}