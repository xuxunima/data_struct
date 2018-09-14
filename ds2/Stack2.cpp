#include<iostream>
using namespace std;

typedef int ElementType;
struct SNode
{
	ElementType data;
	SNode * next;
};

typedef SNode * Stack;
Stack CreateStack();
int isEmpty(Stack S);
void Push(Stack S, ElementType x);
ElementType Pop(Stack S);
void Show(Stack S);
int main()
{
	Stack S = CreateStack();
	int a = isEmpty(S);
	cout << a << endl;
	Push(S, 10);
	Push(S, 2);
	Push(S, 4);
	Show(S);
	Pop(S);
	Show(S);
	Pop(S);
	Pop(S);
	Pop(S);
	return 0;
}

Stack CreateStack()
{
	Stack S = new SNode;
	S->next = nullptr;
	return S;
}

int isEmpty(Stack S)
{
	if (S->next == nullptr)
		return 1;
	else
		return 0;
}

void Push(Stack S, ElementType x)
{
	Stack P = new SNode;
	P->data = x;
	P->next = S->next;
	S->next = P;
}

ElementType Pop(Stack S)
{
	if (S->next == nullptr)
	{
		cout << "the stack is empty" << endl;
		return -1;
	}
	Stack P = S->next;
	S->next = P->next;
	ElementType n = P->data;
	delete P;
	return n;
}

void Show(Stack S)
{
	Stack p = S->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}