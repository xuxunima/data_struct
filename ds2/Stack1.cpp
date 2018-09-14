#include<iostream>
using namespace std;

const int MAX_NUM = 10;
typedef int ElementType;
struct SNode
{
	ElementType data[MAX_NUM];
	int top;
};

typedef SNode * Stack;
Stack CreateStack();
int isFull(Stack S, int max_size);
void Push(Stack S, ElementType x);
int isEmpty(Stack S);
ElementType Pop(Stack S);
void Show(Stack S);
int main()
{
	Stack S = CreateStack();
	int a = isEmpty(S);
	cout << a << endl;
	Push(S, 2);
	Push(S, 3);
	a = isEmpty(S);
	cout << a << endl;
	Show(S);
	Pop(S);
	Show(S);
	return 0;
}

Stack CreateStack()
{
	Stack S = new SNode;
	S->top = -1;
	return S;
}

int isFull(Stack S, int max_size)
{
	if (S->top == max_size - 1)
		return 1;
	else
		return 0;
}

void Push(Stack S, ElementType x)
{
	if (S->top == MAX_NUM-1)
	{
		cout << "the Stack is full" << endl;
		return;
	}
	S->data[++(S->top)] = x;
}

int isEmpty(Stack S)
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}

ElementType Pop(Stack S)
{
	if (S->top == -1)
	{
		cout << "the stack is empty" << endl;
		return 0;
	}
	return S->data[(S->top)--];
}

void Show(Stack S)
{
	for (int i = 0; i <= S->top; i++)
		cout << S->data[i] << " ";
	cout << endl;
}
