#include<iostream>
using namespace std;


typedef int ElementType;

const int MAX_SIZE = 4;
struct QNode
{
	ElementType Data[MAX_SIZE];
	int front;
	int rear;
};

typedef QNode * Queue;
void ShowQ(QNode Q);
Queue CreateQueue();
bool isFull(Queue Q);
bool isEmpty(Queue Q);
bool AddQ(Queue Q, ElementType x);
ElementType DeleteQ(Queue Q);

int main()
{
	Queue Q = CreateQueue();
	AddQ(Q, 3);
	AddQ(Q, 5);
	DeleteQ(Q);
	AddQ(Q, 4);
	DeleteQ(Q);
	AddQ(Q, 10);
	AddQ(Q, 11);
	ShowQ(*Q);
	cout << Q->front << " " << Q->rear << endl;
	return 0;
}

Queue CreateQueue()
{
	Queue Q = new QNode;
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

bool isFull(Queue Q)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front)
		return true;
	else
		return false;
}

bool isEmpty(Queue Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool AddQ(Queue Q, ElementType x)
{
	if ((Q->rear + 1) % MAX_SIZE == Q->front)
	{
		cout << "the queue is full" << endl;
		return false;
	}
	Q->rear = (Q->rear + 1) % MAX_SIZE;
	Q->Data[Q->rear] = x;
	return true;
}

ElementType DeleteQ(Queue Q)
{
	if (Q->front == Q->rear)
	{
		cout << "the queue is empty" << endl;
		return 0;
	}
	Q->front = (Q->front + 1) % MAX_SIZE;
	return Q->Data[Q->front];
}

void ShowQ(QNode Q)
{
	while (Q.front != Q.rear)
	{
		Q.front = (Q.front + 1) % MAX_SIZE;
		cout << Q.Data[Q.front] << " ";
	}
	cout << endl;
}