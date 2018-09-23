#include<iostream>
#include"Stack.h"



Stack CreateStack()
{
	Stack S = new SNode;
	S->next = nullptr;
	return S;
}

bool isEmpty(Stack S)
{
	if (S->next == nullptr)
		return true;
	else
		return false;
}

void Push(Stack S, ElementType BT)
{
	Stack T = new SNode;
	T->data = BT;
	T->next = S->next;
	S->next = T;
}

ElementType Pop(Stack S)
{
	Stack T;
	T = S->next;
	S->next = T->next;
	return T->data;
}

void Show(Stack S)
{
	Stack T = S->next;
	while (T)
	{
		cout << T->data->data << " ";
		T = T->next;
	}
	cout << endl;
}