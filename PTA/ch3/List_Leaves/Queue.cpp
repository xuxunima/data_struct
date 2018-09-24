#include<iostream>
#include"Queue.h"
using namespace std;



Queue CreateQueue()
{
	Queue Q = new QNode;
	Q->front = Q->rear = new Node;
	Q->front->next = nullptr;

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
	Node * T = new Node;
	T->data = x;
	T->next = nullptr;
	Q->rear->next = T;
	Q->rear = T;
}

ElementType DeleteQ(Queue Q)
{
	Node * T = Q->front->next;
	Q->front->next = T->next;
	if (Q->rear == T)
		Q->rear = Q->front;
	return T->data;
}

void Show(Queue Q)
{
	Node * T = Q->front->next;
	while (T != Q->rear)
	{
		cout << T->data<< " ";
		T = T->next;
	}
	cout << Q->rear->data;
	cout << endl;
}