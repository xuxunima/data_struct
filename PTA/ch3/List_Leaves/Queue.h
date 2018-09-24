#pragma once
#include"Leaves.h"
typedef Tree ElementType;
struct Node
{
	ElementType data;
	Node * next;
};

struct QNode
{
	Node * front;
	Node * rear;

};
typedef QNode* Queue;

Queue CreateQueue();
bool isEmpty(Queue Q);
void AddQ(Queue Q, ElementType x);
ElementType DeleteQ(Queue Q);
void Show(Queue Q);